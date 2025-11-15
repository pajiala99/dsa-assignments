#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr) {}
};

Node* insertEnd(Node* head, int x) {
    Node* n = new Node(x);
    if (!head) return n;
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
    return head;
}

bool isCircular(Node* head) {
    if (!head) return false;
    Node* t = head->next;
    while (t && t != head) t = t->next;
    return t == head;
}

int main() {
    Node* head = nullptr;
    head = insertEnd(head, 2);
    head = insertEnd(head, 4);
    head = insertEnd(head, 6);
    head = insertEnd(head, 7);
    head = insertEnd(head, 5);

    Node* tail = head;
    while (tail->next) tail = tail->next;
    tail->next = head;

    cout << (isCircular(head) ? "True" : "False");
    return 0;
}
