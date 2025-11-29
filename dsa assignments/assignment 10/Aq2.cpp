#include <bits/stdc++.h>
using namespace std;
bool hasPairWithSum(int arr[], int n, int target) {
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
        int need = target - arr[i];
        if (s.find(need) != s.end()) return true;
        s.insert(arr[i]);
    }
    return false;
}
int main() {
    int a1[] = {0,-1,2,-3,1};
    cout << (hasPairWithSum(a1, 5, -2) ? "true\n" : "false\n"); 
    int a2[] = {1,-2,1,0,5};
    cout << (hasPairWithSum(a2, 5, 0) ? "true\n" : "false\n"); 
    return 0;
}
