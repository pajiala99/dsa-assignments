#include <bits/stdc++.h>
using namespace std;

void bfs(int n, vector<int> adj[], int start) {
    int visited[1005] = {0};
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!visited[v]) {
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
    vector<int> adj[1005];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    int start;
    cin >> start;

    bfs(n, adj, start);
    return 0;
}
