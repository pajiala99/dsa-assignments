#include <bits/stdc++.h>
using namespace std;

void countSort(int a[], int n, int exp) {
    int out[1000];
    int c[10] = {0};
    for (int i = 0; i < n; i++) c[(a[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int d = (a[i] / exp) % 10;
        out[--c[d]] = a[i];
    }
    for (int i = 0; i < n; i++) a[i] = out[i];
}

void radixSort(int a[], int n) {
    int mx = a[0];
    for (int i = 1; i < n; i++) if (a[i] > mx) mx = a[i];
    for (int exp = 1; mx / exp > 0; exp *= 10)
        countSort(a, n, exp);
}

int main() {
    int n, a[1000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    radixSort(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
