#include <bits/stdc++.h>
using namespace std;

struct Edge { int u, v; long long w; };
struct DSU {
    int n; int *p;
    DSU(int n=0) : n(n) { p = new int[n + 1]; for (int i = 1; i <= n; i++) p[i] = i; }
    ~DSU() { delete[] p; }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) { a = find(a); b = find(b); if (a == b) return false; p[b] = a; return true; }
};

Edge edges[100005];
int edgesCount[100005];
pair<int, long long> adj[1005][100];
int adjConnections[1005];
int used[1005], parent[1005];
long long key[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    int edgeIndex = 0;
    for (int i = 0; i < m; i++) {
        int u, v; long long w;
        cin >> u >> v >> w;
        edges[edgeIndex++] = {u, v, w};
        adj[u][adjConnections[u]++] = {v, w};
        adj[v][adjConnections[v]++] = {u, w};
    }
    int start; cin >> start;

    sort(edges, edges + edgeIndex, [](const Edge &a, const Edge &b) { return a.w < b.w; });
    DSU dsu(n);
    Edge kruskalMST[100005];
    int mstIndex = 0;
    long long kruskalCost = 0;
    for (int i = 0; i < edgeIndex; i++) {
        Edge e = edges[i];
        if (dsu.unite(e.u, e.v)) {
            kruskalMST[mstIndex++] = e;
            kruskalCost += e.w;
        }
    }

    if (mstIndex != n - 1) {
        cout << "MST does not exist (graph disconnected)\n";
    } else {
        for (int i = 0; i < mstIndex; i++) cout << kruskalMST[i].u << " " << kruskalMST[i].v << " " << kruskalMST[i].w << "\n";
        cout << "Total Cost: " << kruskalCost << "\n";
    }

    for (int i = 1; i <= n; i++) key[i] = LLONG_MAX;
    for (int i = 1; i <= n; i++) used[i] = 0, parent[i] = -1;
    key[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int u = pq.top().second;
        long long kw = pq.top().first;
        pq.pop();
        if (used[u]) continue;
        used[u] = 1;
        for (int i = 0; i < adjConnections[u]; i++) {
            int v = adj[u][i].first;
            long long w = adj[u][i].second;

            if (!used[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    Edge primMST[100005];
    mstIndex = 0;
    long long primCost = 0;
    int reached = 0;
    for (int i = 1; i <= n; i++) if (used[i]) reached++;
    if (reached != n) {
        cout << "MST does not exist (graph disconnected)\n";
    } else {
        for (int v = 1; v <= n; v++) {
            if (v == start) continue;
            if (parent[v] != -1) {
                primMST[mstIndex++] = {parent[v], v, key[v]};
                primCost += key[v];
            }
        }
        for (int i = 0; i < mstIndex; i++) cout << primMST[i].u << " " << primMST[i].v << " " << primMST[i].w << "\n";
        cout << "Total Cost: " << primCost << "\n";
    }

    return 0;
}
