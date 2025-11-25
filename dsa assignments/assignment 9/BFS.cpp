#include <bits/stdc++.h>
using namespace std;

void bfs(int n, int adj[][1005], int start) {
    int visited[1005] = {0};
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v = 1; v <= n; v++) { 
            if (adj[u][v] && !visited[v]) { 
visited[v] = 1;
                q.push(v);
            }
        }
    }
    cout << "\n";
}

int main() {
    int n, m;
    cin >> n >> m;
    int adj[1005][1005] = {0}; // Adjacency matrix initialized to 0

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph
    }

    int start;
    cin >> start;

    bfs(n, adj, start);
    return 0;
}
