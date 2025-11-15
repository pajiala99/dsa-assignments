#include <bits/stdc++.h>
using namespace std;

void heapifyMax(int a[], int n, int i) {
    while (true) {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < n && a[l] > a[largest]) largest = l;
        if (r < n && a[r] > a[largest]) largest = r;
        if (largest == i) break;
        swap(a[i], a[largest]);
        i = largest;
    }
}

void heapifyMin(int a[], int n, int i) {
    while (true) {
        int smallest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < n && a[l] < a[smallest]) smallest = l;
        if (r < n && a[r] < a[smallest]) smallest = r;
        if (smallest == i) break;
        swap(a[i], a[smallest]);
        i = smallest;
    }
}

void heapSortIncreasing(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; --i) heapifyMax(a, n, i);
    for (int end = n - 1; end > 0; --end) {
        swap(a[0], a[end]);
        heapifyMax(a, end, 0);
    }
}

void heapSortDecreasing(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; --i) heapifyMin(a, n, i);
    for (int end = n - 1; end > 0; --end) {
        swap(a[0], a[end]);
        heapifyMin(a, end, 0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    int choice;
    cin >> choice; // 1 -> increasing, 2 -> decreasing

    if (choice == 1) heapSortIncreasing(a, n);
    else heapSortDecreasing(a, n);

    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << '\n';

    delete [] a;
    return 0;
}
