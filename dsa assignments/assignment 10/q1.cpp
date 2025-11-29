#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(int arr[], int n) {
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
        if (s.find(arr[i]) != s.end()) return true;
        s.insert(arr[i]);
    }
    return false;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int n = sizeof(nums)/sizeof(nums[0]);
    cout << (containsDuplicate(nums, n) ? "true\n" : "false\n");
    return 0;
}
