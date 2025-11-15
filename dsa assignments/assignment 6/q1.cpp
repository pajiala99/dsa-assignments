#include <bits/stdc++.h>
using namespace std;

struct CNode {
    int val;
    CNode* next;
    CNode(int x): val(x), next(nullptr) {}
};

class CircularList {
    CNode* head;
public:
    CircularList(): head(nullptr) {}
    ~CircularList() { clear(); }
    bool isEmpty() const { return head == nullptr; }
    void insertAtBeginning(int x) {
        CNode* node = new CNode(x);
        if (!head) { head = node; head->next = head; return; }
        CNode* tail = head;
        while (tail->next != head) tail = tail->next;
        node->next = head;
        tail->next = node;
        head = node;
    }
    void insertAtEnd(int x) {
        CNode* node = new CNode(x);
        if (!head) { head = node; head->next = head; return; }
        CNode* tail = head;
        while (tail->next != head) tail = tail->next;
        tail->next = node;
        node->next = head;
    }
    bool insertAfter(int key, int x) {
        if (!head) return false;
        CNode* cur = head;
        do {
            if (cur->val == key) {
                CNode* node = new CNode(x);
                node->next = cur->next;
                cur->next = node;
                return true;
            }
            cur = cur->next;
        } while (cur != head);
        return false;
    }
    bool insertBefore(int key, int x) {
        if (!head) return false;
        if (head->val == key) { insertAtBeginning(x); return true; }
        CNode* prev = head;
        CNode* cur = head->next;
        while (cur != head) {
            if (cur->val == key) {
                CNode* node = new CNode(x);
                node->next = cur;
                prev->next = node;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }
    bool deleteValue(int key) {
        if (!head) return false;
        if (head->next == head) {
            if (head->val == key) { delete head; head = nullptr; return true; }
            return false;
        }
        if (head->val == key) {
            CNode* tail = head;
            while (tail->next != head) tail = tail->next;
            CNode* del = head;
            head = head->next;
            tail->next = head;
            delete del;
            return true;
        }
        CNode* prev = head;
        CNode* cur = head->next;
        while (cur != head) {
            if (cur->val == key) {
                prev->next = cur->next;
                delete cur;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }
    int search(int key) const {
        if (!head) return 0;
        CNode* cur = head;
        int pos = 1;
        do {
            if (cur->val == key) return pos;
            cur = cur->next;
            pos++;
        } while (cur != head);
        return 0;
    }
    void print() const {
        if (!head) { cout << "(empty)\n"; return; }
        CNode* cur = head;
        cout << "HEAD -> ";
        do {
            cout << cur->val << " -> ";
            cur = cur->next;
        } while (cur != head);
        cout << "(HEAD)\n";
    }
    void clear() {
        if (!head) return;
        CNode* tail = head;
        while (tail->next != head) tail = tail->next;
        tail->next = nullptr;
        CNode* cur = head;
        while (cur) {
            CNode* nx = cur->next;
            delete cur;
            cur = nx;
        }
        head = nullptr;
    }
};

struct DNode {
    int val;
    DNode* prev;
    DNode* next;
    DNode(int x): val(x), prev(nullptr), next(nullptr) {}
};

class DoublyList {
    DNode* head;
public:
    DoublyList(): head(nullptr) {}
    ~DoublyList() { clear(); }
    bool isEmpty() const { return head == nullptr; }
    void insertAtBeginning(int x) {
        DNode* node = new DNode(x);
        node->next = head;
        if (head) head->prev = node;
        head = node;
    }
    void insertAtEnd(int x) {
        DNode* node = new DNode(x);
        if (!head) { head = node; return; }
        DNode* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = node;
        node->prev = cur;
    }
    bool insertAfter(int key, int x) {
        DNode* cur = head;
        while (cur) {
            if (cur->val == key) {
                DNode* node = new DNode(x);
                node->next = cur->next;
                node->prev = cur;
                if (cur->next) cur->next->prev = node;
                cur->next = node;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
    bool insertBefore(int key, int x) {
        DNode* cur = head;
        while (cur) {
            if (cur->val == key) {
                DNode* node = new DNode(x);
                node->next = cur;
                node->prev = cur->prev;
                if (cur->prev) cur->prev->next = node;
                else head = node;
                cur->prev = node;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
    bool deleteValue(int key) {
        DNode* cur = head;
        while (cur) {
            if (cur->val == key) {
                if (cur->prev) cur->prev->next = cur->next;
                else head = cur->next;
                if (cur->next) cur->next->prev = cur->prev;
                delete cur;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
    int search(int key) const {
        DNode* cur = head;
        int pos = 1;
        while (cur) {
            if (cur->val == key) return pos;
            cur = cur->next;
            pos++;
        }
        return 0;
    }
    void printForward() const {
        if (!head) { cout << "(empty)\n"; return; }
        DNode* cur = head;
        cout << "HEAD -> ";
        while (cur) {
            cout << cur->val;
            if (cur->next) cout << " <-> ";
            cur = cur->next;
        }
        cout << " -> NULL\n";
    }
    void printBackward() const {
        if (!head) { cout << "(empty)\n"; return; }
        DNode* cur = head;
        while (cur->next) cur = cur->next;
        cout << "TAIL -> ";
        while (cur) {
            cout << cur->val;
            if (cur->prev) cout << " <-> ";
            cur = cur->prev;
        }
        cout << " -> NULL\n";
    }
    void clear() {
        DNode* cur = head;
        while (cur) {
            DNode* nx = cur->next;
            delete cur;
            cur = nx;
        }
        head = nullptr;
    }
};

int readInt() {
    int x;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter integer: ";
    }
    return x;
}

void circularMenu(CircularList &cl) {
    while (true) {
        cout << "\n--- Circular List Menu ---\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert after\n4. Insert before\n5. Delete value\n6. Search\n7. Print\n8. Clear\n0. Back\nChoose: ";
        int ch = readInt();
        if (ch == 0) break;
        int x, key;
        bool ok;
        switch (ch) {
            case 1:
                cout << "Value: "; x = readInt();
                cl.insertAtBeginning(x); break;
            case 2:
                cout << "Value: "; x = readInt();
                cl.insertAtEnd(x); break;
            case 3:
                cout << "After value: "; key = readInt();
                cout << "Value: "; x = readInt();
                cout << (cl.insertAfter(key,x)?"Done\n":"Not found\n"); break;
            case 4:
                cout << "Before value: "; key = readInt();
                cout << "Value: "; x = readInt();
                cout << (cl.insertBefore(key,x)?"Done\n":"Not found\n"); break;
            case 5:
                cout << "Delete value: "; key = readInt();
                cout << (cl.deleteValue(key)?"Deleted\n":"Not found\n"); break;
            case 6:
                cout << "Search value: "; key = readInt();
                cout << cl.search(key) << "\n"; break;
            case 7:
                cl.print(); break;
            case 8:
                cl.clear(); cout << "Cleared\n"; break;
            default:
                cout << "Invalid\n";
        }
    }
}

void doublyMenu(DoublyList &dl) {
    while (true) {
        cout << "\n--- Doubly List Menu ---\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert after\n4. Insert before\n5. Delete value\n6. Search\n7. Print forward\n8. Print backward\n9. Clear\n0. Back\nChoose: ";
        int ch = readInt();
        if (ch == 0) break;
        int x, key;
        switch (ch) {
            case 1:
                cout << "Value: "; x = readInt();
                dl.insertAtBeginning(x); break;
            case 2:
                cout << "Value: "; x = readInt();
                dl.insertAtEnd(x); break;
            case 3:
                cout << "After value: "; key = readInt();
                cout << "Value: "; x = readInt();
                cout << (dl.insertAfter(key,x)?"Done\n":"Not found\n"); break;
            case 4:
                cout << "Before value: "; key = readInt();
                cout << "Value: "; x = readInt();
                cout << (dl.insertBefore(key,x)?"Done\n":"Not found\n"); break;
            case 5:
                cout << "Delete value: "; key = readInt();
                cout << (dl.deleteValue(key)?"Deleted\n":"Not found\n"); break;
            case 6:
                cout << "Search value: "; key = readInt();
                cout << dl.search(key) << "\n"; break;
            case 7:
                dl.printForward(); break;
            case 8:
                dl.printBackward(); break;
            case 9:
                dl.clear(); cout << "Cleared\n"; break;
            default:
                cout << "Invalid\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    CircularList cl;
    DoublyList dl;
    while (true) {
        cout << "\n=== Main Menu ===\n";
        cout << "1. Circular Linked List\n2. Doubly Linked List\n0. Exit\nChoose: ";
        int ch = readInt();
        if (ch == 0) break;
        if (ch == 1) circularMenu(cl);
        else if (ch == 2) doublyMenu(dl);
        else cout << "Invalid\n";
    }
    return 0;
}
