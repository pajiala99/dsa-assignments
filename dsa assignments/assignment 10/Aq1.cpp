#include <bits/stdc++.h>
using namespace std;
int mostFrequentLargestOnTie(int arr[], int n) {
    unordered_map<int,int> freq;
    for (int i = 0; i < n; ++i) freq[arr[i]]++;
    int bestVal = INT_MIN;
    int bestFreq = 0;
    for (auto &p : freq) {
        int val = p.first, f = p.second;
        if (f > bestFreq || (f == bestFreq && val > bestVal)) {
            bestFreq = f;
            bestVal = val;
        }
    }
    return bestVal;
}
int main() {
    int arr1[] = {1,3,2,1,4,1}; 
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    cout << mostFrequentLargestOnTie(arr1, n1) << "\n";

    int arr2[] = {1,2,2,4,1}; 
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    cout << mostFrequentLargestOnTie(arr2, n2) << "\n";

    return 0;
}
