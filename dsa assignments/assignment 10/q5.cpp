#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr) {}
};
bool hasCycle(Node* head) {
    unordered_set<Node*> seen;
    Node* cur = head;
    while (cur) {
        if (seen.find(cur) != seen.end()) return true;
        seen.insert(cur);
        cur = cur->next;
    }
    return false;
}
int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n2; 
    cout << (hasCycle(n1) ? "true\n" : "false\n");
    return 0;
}
