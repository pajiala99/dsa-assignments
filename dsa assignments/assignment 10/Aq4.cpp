#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr) {}
};
Node* append(Node* tail, int val) {
    Node* n = new Node(val);
    if (!tail) return n;
    tail->next = n;
    return n;
}
Node* makeListFromArray(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < n; ++i) {
        tail = append(tail, arr[i]);
    }
    return head;
}
void printList(Node* head) {
    Node* cur = head;
    bool first = true;
    while (cur) {
        if (!first) cout << " -> ";
        cout << cur->val;
        first = false;
        cur = cur->next;
    }
    cout << "\n";
}
void unionAndIntersection(Node* head1, Node* head2, Node*& unionHead, Node*& interHead) {
    unordered_set<int> s1;
    for (Node* p = head1; p; p = p->next) s1.insert(p->val);
    unordered_set<int> s2;
    for (Node* p = head2; p; p = p->next) s2.insert(p->val);
    Node* interTail = nullptr;
    interHead = nullptr;
    for (auto val : s1) {
        if (s2.find(val) != s2.end()) {
            if (!interHead) interHead = new Node(val), interTail = interHead;
            else interTail = append(interTail, val);
        }
    }
    Node* unionTail = nullptr;
    unionHead = nullptr;
    for (auto val : s1) {
        if (!unionHead) unionHead = new Node(val), unionTail = unionHead;
        else unionTail = append(unionTail, val);
    }
    for (auto val : s2) {
        if (s1.find(val) == s1.end()) {
            if (!unionHead) unionHead = new Node(val), unionTail = unionHead;
            else unionTail = append(unionTail, val);
        }
    }
}
int main() {
    int arr1[] = {10,15,4,20};
    int arr2[] = {8,4,2,10};
    Node* h1 = makeListFromArray(arr1, 4);
    Node* h2 = makeListFromArray(arr2, 4);
    Node* unionHead = nullptr;
    Node* interHead = nullptr;
    unionAndIntersection(h1, h2, unionHead, interHead);
    cout << "Intersection List: ";
    if (interHead) printList(interHead); else cout << "Empty\n";
    cout << "Union List: ";
    if (unionHead) printList(unionHead); else cout << "Empty\n";
    return 0;
}
