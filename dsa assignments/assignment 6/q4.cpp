#include <bits/stdc++.h>
using namespace std;

struct DNode {
    char val;
    DNode* prev;
    DNode* next;
    DNode(char c): val(c), prev(nullptr), next(nullptr) {}
};

DNode* insertEnd(DNode* head, char c) {
    DNode* n = new DNode(c);
    if (!head) return n;
    DNode* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
    return head;
}

bool isPalindrome(DNode* head) {
    if (!head) return true;
    DNode* tail = head;
    while (tail->next) tail = tail->next;
    DNode* l = head;
    DNode* r = tail;
    while (l != r && l->prev != r) {
        if (l->val != r->val) return false;
        l = l->next;
        r = r->prev;
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    DNode* head = nullptr;
    for (char c : s) {
        if (!isspace(static_cast<unsigned char>(c))) head = insertEnd(head, c);
    }
    cout << (isPalindrome(head) ? "True" : "False") << '\n';
    return 0;
}
