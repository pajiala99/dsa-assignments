#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};
bool hasDuplicates(TreeNode* root) {
    if (!root) return false;
    unordered_set<int> seen;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* t = q.front(); q.pop();
        if (seen.find(t->val) != seen.end()) return true;
        seen.insert(t->val);
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
    }
    return false;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    cout << (hasDuplicates(root) ? "Duplicates Found\n" : "No Duplicates\n");
    return 0;
}
