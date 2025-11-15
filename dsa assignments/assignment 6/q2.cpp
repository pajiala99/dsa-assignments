#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr) {}
};

Node* insertEnd(Node* head, int x) {
    Node* n = new Node(x);
    if (!head) {
        head = n;
        head->next = head;
        return head;
    }
    Node* t = head;
    while (t->next != head) t = t->next;
    t->next = n;
    n->next = head;
    return head;
}

void displayCircular(Node* head) {
    if (!head) return;
    Node* cur = head;
    do {
        cout << cur->val << " ";
        cur = cur->next;
    } while (cur != head);
    cout << head->val;
}

int main() {
    Node* head = nullptr;
    head = insertEnd(head, 20);
    head = insertEnd(head, 100);
    head = insertEnd(head, 40);
    head = insertEnd(head, 80);
    head = insertEnd(head, 60);

    displayCircular(head);
    return 0;
}
