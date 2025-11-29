
#include <bits/stdc++.h>
using namespace std;

void printCommon(int A[], int n, int B[], int m) {
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) s.insert(A[i]);
    unordered_set<int> printed;
    bool first = true;
    for (int j = 0; j < m; ++j) {
        if (s.find(B[j]) != s.end() && printed.find(B[j]) == printed.end()) {
            if (!first) cout << ", ";
            cout << B[j];
            first = false;
            printed.insert(B[j]);
        }
    }
    cout << "\n";
}

int main() {
    int A[] = {1,2,3,4};
    int B[] = {3,4,5,6};
    int n = sizeof(A)/sizeof(A[0]);
    int m = sizeof(B)/sizeof(B[0]);
    printCommon(A, n, B, m); 
    return 0;
}
