#include <bits/stdc++.h>
using namespace std;

int visited[1005];

void dfsUtil(int u, vector<int> adj[]) {
    visited[u] = 1;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v]) dfsUtil(v, adj);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[1005];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cin >> start;

    memset(visited, 0, sizeof(visited));
    dfsUtil(start, adj);
    return 0;
}
