#include <bits/stdc++.h>
using namespace std;

int firstNonRepeating(int arr[], int n) {
    unordered_map<int,int> freq;
    for (int i = 0; i < n; ++i) freq[arr[i]]++;
    for (int i = 0; i < n; ++i) if (freq[arr[i]] == 1) return arr[i];
    return INT_MIN; 
}

int main() {
    int arr[] = {4,5,1,2,0,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = firstNonRepeating(arr, n);
    if (ans != INT_MIN) cout << ans << "\n"; else cout << "No non-repeating element\n";
    return 0;
}
