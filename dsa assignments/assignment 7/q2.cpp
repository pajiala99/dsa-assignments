#include <bits/stdc++.h>
using namespace std;

void improvedSelectionSort(int a[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int mn = left, mx = right;
        for (int i = left; i <= right; i++) {
            if (a[i] < a[mn]) mn = i;
            if (a[i] > a[mx]) mx = i;
        }
        swap(a[left], a[mn]);
        if (mx == left) mx = mn;
        swap(a[right], a[mx]);
        left++;
        right--;
    }
}

int main() {
    int n;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++) cin >> a[i];
    improvedSelectionSort(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
