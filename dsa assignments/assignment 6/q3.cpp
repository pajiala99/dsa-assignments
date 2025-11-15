#include <bits/stdc++.h>
using namespace std;

struct DNode {
    int val;
    DNode* next;
    DNode* prev;
    DNode(int x): val(x), next(nullptr), prev(nullptr) {}
};

struct CNode {
    int val;
    CNode* next;
    CNode(int x): val(x), next(nullptr) {}
};

DNode* insertD(DNode* head, int x) {
    DNode* n = new DNode(x);
    if (!head) return n;
    DNode* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
    return head;
}

CNode* insertC(CNode* head, int x) {
    CNode* n = new CNode(x);
    if (!head) {
        head = n;
        head->next = head;
        return head;
    }
    CNode* t = head;
    while (t->next != head) t = t->next;
    t->next = n;
    n->next = head;
    return head;
}

int sizeD(DNode* head) {
    int c = 0;
    DNode* t = head;
    while (t) {
        c++;
        t = t->next;
    }
    return c;
}

int sizeC(CNode* head) {
    if (!head) return 0;
    int c = 0;
    CNode* t = head;
    do {
        c++;
        t = t->next;
    } while (t != head);
    return c;
}

int main() {
    DNode* dhead = nullptr;
    dhead = insertD(dhead, 10);
    dhead = insertD(dhead, 20);
    dhead = insertD(dhead, 30);
    dhead = insertD(dhead, 40);

    CNode* chead = nullptr;
    chead = insertC(chead, 5);
    chead = insertC(chead, 15);
    chead = insertC(chead, 25);

    cout << "Size of Doubly Linked List: " << sizeD(dhead) << "\n";
    cout << "Size of Circular Linked List: " << sizeC(chead) << "\n";

    return 0;
}
