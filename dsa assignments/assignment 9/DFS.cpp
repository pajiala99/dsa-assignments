#include <bits/stdc++.h>
using namespace std;

int visited[1005];

void dfsUtil(int u, int adj[][1005], int n) {
    visited[u] = 1;
    cout << u << " ";
    for (int v = 1; v <= n; v++) {
        if (adj[u][v] && !visited[v]) dfsUtil(v, adj, n);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int adj[1005][1005] = {0};

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int start;
    cin >> start;

    memset(visited, 0, sizeof(visited));
    dfsUtil(start, adj, n);
    return 0;
}