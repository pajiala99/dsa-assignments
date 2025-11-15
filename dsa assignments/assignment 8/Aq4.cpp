#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

Node* build(const vector<int>& a) {
    int n = a.size();
    if (n == 0 || a[0] == -1) return nullptr;
    vector<Node*> nodes(n, nullptr);
    for (int i = 0; i < n; i++)
        if (a[i] != -1) nodes[i] = new Node(a[i]);
    for (int i = 0; i < n; i++) {
        if (!nodes[i]) continue;
        int l = 2*i + 1, r = 2*i + 2;
        if (l < n) nodes[i]->left = nodes[l];
        if (r < n) nodes[i]->right = nodes[r];
    }
    return nodes[0];
}

vector<int> rightView(Node* root) {
    vector<int> res;
    if (!root) return res;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        Node* last = nullptr;
        for (int i = 0; i < sz; i++) {
            Node* cur = q.front(); q.pop();
            last = cur;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        res.push_back(last->val);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        Node* root = build(a);
        vector<int> ans = rightView(root);
        for (int i = 0; i < ans.size(); i++) {
            if (i) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}
