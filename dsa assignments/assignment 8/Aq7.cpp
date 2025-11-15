#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

Node* insertBST(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->val) root->left = insertBST(root->left, x);
    else root->right = insertBST(root->right, x);
    return root;
}

void inorder(Node* root, vector<int>& v) {
    if (!root) return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}

struct DNode {
    int val;
    DNode* prev;
    DNode* next;
    DNode(int v): val(v), prev(nullptr), next(nullptr) {}
};

DNode* mergeToDLL(const vector<int>& a, const vector<int>& b) {
    int i = 0, j = 0, n = a.size(), m = b.size();
    DNode* head = nullptr;
    DNode* tail = nullptr;
    auto add = [&](int x) {
        DNode* nn = new DNode(x);
        if (!head) { head = tail = nn; }
        else {
            tail->next = nn;
            nn->prev = tail;
            tail = nn;
        }
    };
    while (i < n && j < m) {
        if (a[i] < b[j]) add(a[i++]);
        else add(b[j++]);
    }
    while (i < n) add(a[i++]);
    while (j < m) add(b[j++]);
    return head;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1, n2;
    cin >> n1;
    Node* t1 = nullptr;
    for (int i = 0; i < n1; i++) {
        int x; cin >> x;
        t1 = insertBST(t1, x);
    }

    cin >> n2;
    Node* t2 = nullptr;
    for (int i = 0; i < n2; i++) {
        int x; cin >> x;
        t2 = insertBST(t2, x);
    }

    vector<int> A, B;
    inorder(t1, A);
    inorder(t2, B);

    DNode* head = mergeToDLL(A, B);

    DNode* cur = head;
    while (cur) {
        cout << cur->val << " <—> ";
        cur = cur->next;
    }
    cout << "null\n";

    return 0;
}
