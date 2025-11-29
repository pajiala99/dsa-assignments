#include <bits/stdc++.h>
using namespace std;

void printFrequencies(int arr[], int n) {
    unordered_map<int,int> freq;
    for (int i = 0; i < n; ++i) freq[arr[i]]++;
    for (auto &p : freq) {
        cout << p.first << " -> " << p.second << (p.second == 1 ? " time\n" : " times\n");
    }
}

int main() {
    int nums[] = {2,3,2,4,3,2};
    int n = sizeof(nums)/sizeof(nums[0]);
    printFrequencies(nums, n);
    return 0;
}
