#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    const long long INF = (1LL<<60);
    vector<pair<int,long long>> adj[100005];
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int src;
    cin >> src;
    vector<long long> dist(n+1, INF);
    vector<int> vis(n+1, 0);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto &e : adj[u]) {
            int v = e.first; long long w = e.second;
            if (!vis[v] && d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << " ";
        if (dist[i] == INF) cout << "INF"; else cout << dist[i];
    }
    cout << '\n';
    return 0;
}
