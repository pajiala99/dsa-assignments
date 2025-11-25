#include <bits/stdc++.h>
using namespace std;

const long long INF = (1LL<<60);
long long dist[100005];
int vis[100005];
pair<int, long long> adj[100005][100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;

    int edges[100005] = {0};
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u][edges[u]++] = {v, w};
        adj[v][edges[v]++] = {u, w};
    }

    int src;
    cin >> src;
    for (int i = 1; i <= n; ++i) dist[i] = INF;

    priority_queue<pair<long long, int>, 
        vector<pair<long long, int>>, 
        greater<pair<long long, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();

        if (vis[u]) continue;
        vis[u] = 1;

        for (int i = 0; i < edges[u]; i++) {
            int v = adj[u][i].first;
            long long w = adj[u][i].second;

            if (!vis[v] && d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << " ";
        if (dist[i] == INF) cout << "INF";
        else cout << dist[i];
    }
    cout << '\n';
    return 0;
}
