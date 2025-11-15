#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

vector<TreeNode*> gen(int l, int r, unordered_map<string, vector<TreeNode*>>& memo) {
    string key = to_string(l) + "#" + to_string(r);
    if (memo.count(key)) return memo[key];
    vector<TreeNode*> res;
    if (l > r) {
        res.push_back(nullptr);
        memo[key] = res;
        return res;
    }
    for (int i = l; i <= r; ++i) {
        vector<TreeNode*> lefts = gen(l, i - 1, memo);
        vector<TreeNode*> rights = gen(i + 1, r, memo);
        for (TreeNode* L : lefts) {
            for (TreeNode* R : rights) {
                TreeNode* root = new TreeNode(i);
                root->left = L;
                root->right = R;
                res.push_back(root);
            }
        }
    }
    memo[key] = res;
    return res;
}

vector<int> serialize(TreeNode* root) {
    vector<int> out;
    if (!root) return out;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* t = q.front(); q.pop();
        if (t) {
            out.push_back(t->val);
            q.push(t->left);
            q.push(t->right);
        } else {
            out.push_back(INT_MIN);
        }
    }
    while (!out.empty() && out.back() == INT_MIN) out.pop_back();
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    unordered_map<string, vector<TreeNode*>> memo;
    vector<TreeNode*> trees = gen(1, n, memo);
    cout << "["; 
    for (size_t i = 0; i < trees.size(); ++i) {
        vector<int> s = serialize(trees[i]);
        cout << "[";
        for (size_t j = 0; j < s.size(); ++j) {
            if (s[j] == INT_MIN) cout << "null";
            else cout << s[j];
            if (j + 1 < s.size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < trees.size()) cout << ",";
    }
    cout << "]\n";
    return 0;
}
