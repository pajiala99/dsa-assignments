#include <bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[m]) m = j;
        swap(a[i], a[m]);
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
}

void mergeArr(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[1000], R[1000];
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) R[i] = a[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    mergeArr(a, l, m, r);
}

int partitionQS(int a[], int l, int r) {
    int p = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
        if (a[j] < p) swap(a[++i], a[j]);
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSort(int a[], int l, int r) {
    if (l < r) {
        int pi = partitionQS(a, l, r);
        quickSort(a, l, pi - 1);
        quickSort(a, pi + 1, r);
    }
}

void printArr(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++) cin >> a[i];

    int ch;
    cin >> ch;

    switch (ch) {
        case 1: selectionSort(a, n); break;
        case 2: insertionSort(a, n); break;
        case 3: bubbleSort(a, n); break;
        case 4: mergeSort(a, 0, n - 1); break;
        case 5: quickSort(a, 0, n - 1); break;
        default: return 0;
    }

    printArr(a, n);
    return 0;
}
