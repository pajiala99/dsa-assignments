#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

Node* buildRec(const vector<int>& in, int inL, int inR,
               const vector<int>& post, int postL, int postR,
               const unordered_map<int,int>& idx) {
    if (inL > inR || postL > postR) return nullptr;
    int rootVal = post[postR];
    Node* root = new Node(rootVal);
    int inRootIdx = idx.at(rootVal);
    int leftSize = inRootIdx - inL;
    root->left = buildRec(in, inL, inRootIdx - 1, post, postL, postL + leftSize - 1, idx);
    root->right = buildRec(in, inRootIdx + 1, inR, post, postL + leftSize, postR - 1, idx);
    return root;
}

Node* buildTree(const vector<int>& inorder, const vector<int>& postorder) {
    int n = inorder.size();
    unordered_map<int,int> idx;
    idx.reserve(n*2);
    for (int i = 0; i < n; ++i) idx[inorder[i]] = i;
    return buildRec(inorder, 0, n-1, postorder, 0, n-1, idx);
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
    vector<int> inorder(n), postorder(n);
    for (int i = 0; i < n; ++i) cin >> inorder[i];
    for (int i = 0; i < n; ++i) cin >> postorder[i];
    Node* root = buildTree(inorder, postorder);
    printLevelOrder(root);
    return 0;
}
