#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x): val(x), left(nullptr), right(nullptr) {}
};

Node* buildTree(vector<int>& a) {
    if (a.empty() || a[0] == -1) return nullptr;
    vector<Node*> nodes(a.size(), nullptr);
    for (int i = 0; i < a.size(); i++)
        if (a[i] != -1) nodes[i] = new Node(a[i]);

    for (int i = 0; i < a.size(); i++) {
        if (!nodes[i]) continue;
        int l = 2*i + 1, r = 2*i + 2;
        if (l < a.size()) nodes[i]->left = nodes[l];
        if (r < a.size()) nodes[i]->right = nodes[r];
    }
    return nodes[0];
}

int sumLeftLeaves(Node* root, bool isLeft) {
    if (!root) return 0;
    if (!root->left && !root->right && isLeft) return root->val;
    return sumLeftLeaves(root->left, true) + sumLeftLeaves(root->right, false);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    Node* root = buildTree(a);
    cout << sumLeftLeaves(root, false);
    return 0;
}
