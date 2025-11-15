#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

Node* buildFromLevel(const vector<int>& a) {
    int n = (int)a.size();
    if (n == 0) return nullptr;
    vector<Node*> nodes(n, nullptr);
    for (int i = 0; i < n; ++i) if (a[i] != -1) nodes[i] = new Node(a[i]);
    for (int i = 0; i < n; ++i) {
        if (!nodes[i]) continue;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < n) nodes[i]->left = nodes[l];
        if (r < n) nodes[i]->right = nodes[r];
    }
    return nodes[0];
}

int maxDepth(Node* root) {
    if (!root) return 0;
    int depth = 0;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = (int)q.size();
        ++depth;
        for (int i = 0; i < sz; ++i) {
            Node* cur = q.front(); q.pop();
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    return depth;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        Node* root = buildFromLevel(a);
        cout << maxDepth(root) << '\n';
    }
    return 0;
}
