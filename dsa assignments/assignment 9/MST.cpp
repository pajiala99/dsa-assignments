#include <bits/stdc++.h>
using namespace std;

struct Edge { int u,v; long long w; };
struct DSU {
    int n;
    int *p;
    DSU(int n=0): n(n) { p = new int[n+1]; for (int i=1;i<=n;i++) p[i]=i; }
    ~DSU(){ delete[] p; }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){ a=find(a); b=find(b); if(a==b) return false; p[b]=a; return true; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    if(!(cin>>n>>m)) return 0;
    vector<Edge> edges;
    edges.reserve(m);
    vector<vector<pair<int,long long>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v; long long w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int start; cin>>start;

    // Kruskal
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b){ return a.w < b.w; });
    DSU dsu(n);
    vector<Edge> kruskalMST;
    long long kruskalCost = 0;
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            kruskalMST.push_back(e);
            kruskalCost += e.w;
        }
    }
    cout << "Kruskal MST:\n";
    if ((int)kruskalMST.size() != n-1) {
        cout << "MST does not exist (graph disconnected)\n";
    } else {
        for (auto &e : kruskalMST) cout << e.u << " " << e.v << " " << e.w << "\n";
        cout << "Total Cost: " << kruskalCost << "\n";
    }

    // Prim (using min-heap)
    cout << "Prim MST (starting at " << start << "):\n";
    vector<int> used(n+1,0);
    vector<long long> key(n+1, LLONG_MAX);
    vector<int> parent(n+1,-1);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    key[start]=0;
    pq.push({0,start});
    while(!pq.empty()){
        auto [kw,u] = pq.top(); pq.pop();
        if(used[u]) continue;
        used[u]=1;
        for(auto &pr: adj[u]){
            int v = pr.first;
            long long w = pr.second;
            if(!used[v] && w < key[v]){
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    vector<Edge> primMST;
    long long primCost = 0;
    for(int v=1; v<=n; ++v){
        if(v==start) continue;
        if(parent[v] != -1){
            primMST.push_back({parent[v], v, key[v]});
            primCost += key[v];
        }
    }
    int reached = 0;
    for(int i=1;i<=n;i++) if(used[i]) reached++;
    if (reached != n) {
        cout << "MST does not exist (graph disconnected)\n";
    } else {
        for(auto &e: primMST) cout << e.u << " " << e.v << " " << e.w << "\n";
        cout << "Total Cost: " << primCost << "\n";
    }

    return 0;
}
