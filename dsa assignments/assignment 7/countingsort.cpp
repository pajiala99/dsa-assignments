#include <bits/stdc++.h>
using namespace std;

void countingSort(int a[], int n) {
    int mx = a[0];
    for (int i = 1; i < n; i++) if (a[i] > mx) mx = a[i];
    int c[10000] = {0};
    for (int i = 0; i < n; i++) c[a[i]]++;
    int k = 0;
    for (int i = 0; i <= mx; i++)
        while (c[i]--) a[k++] = i;
}

int main() {
    int n, a[1000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    countingSort(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
