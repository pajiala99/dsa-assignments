#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

Node* buildRec(const vector<int>& pre, int preL, int preR,
               const vector<int>& in, int inL, int inR,
               const unordered_map<int,int>& idx) {
    if (preL > preR || inL > inR) return nullptr;
    int rootVal = pre[preL];
    Node* root = new Node(rootVal);
    int inRootIdx = idx.at(rootVal);
    int leftSize = inRootIdx - inL;
    root->left = buildRec(pre, preL + 1, preL + leftSize, in, inL, inRootIdx - 1, idx);
    root->right = buildRec(pre, preL + leftSize + 1, preR, in, inRootIdx + 1, inR, idx);
    return root;
}

Node* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
    int n = preorder.size();
    unordered_map<int,int> idx;
    idx.reserve(n*2);
    for (int i = 0; i < n; ++i) idx[inorder[i]] = i;
    return buildRec(preorder, 0, n-1, inorder, 0, n-1, idx);
}

void printLevelOrder(Node* root) {
    if (!root) { cout << "\n"; return; }
    queue<Node*> q;
    q.push(root);
    bool first = true;
    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        if (!first) cout << " ";
        cout << cur->val;
        first = false;
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> preorder(n), inorder(n);
    for (int i = 0; i < n; ++i) cin >> preorder[i];
    for (int i = 0; i < n; ++i) cin >> inorder[i];
    Node* root = buildTree(preorder, inorder);
    printLevelOrder(root);
    return 0;
}
