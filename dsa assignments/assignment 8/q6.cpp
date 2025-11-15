#include <bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryHeap {
    T *arr;
    int cap;
    int len;
    bool isMin;
    void ensureCapacity() {
        if (len < cap) return;
        int ncap = max(1, cap * 2);
        T *b = new T[ncap];
        for (int i = 0; i < len; ++i) b[i] = arr[i];
        delete [] arr;
        arr = b;
        cap = ncap;
    }
    bool cmp(const T &a, const T &b) const { return isMin ? a < b : a > b; }
    void heapifyUp(int idx) {
        while (idx > 0) {
            int p = (idx - 1) >> 1;
            if (cmp(arr[idx], arr[p])) { swap(arr[idx], arr[p]); idx = p; }
            else break;
        }
    }
    void heapifyDown(int idx) {
        while (true) {
            int l = (idx << 1) + 1;
            int r = l + 1;
            int best = idx;
            if (l < len && cmp(arr[l], arr[best])) best = l;
            if (r < len && cmp(arr[r], arr[best])) best = r;
            if (best == idx) break;
            swap(arr[idx], arr[best]);
            idx = best;
        }
    }
public:
    BinaryHeap(bool minHeap=false, int initialCap=16): cap(initialCap), len(0), isMin(minHeap) {
        arr = new T[cap];
    }
    ~BinaryHeap(){ delete [] arr; }
    void push(const T &v) {
        ensureCapacity();
        arr[len++] = v;
        heapifyUp(len-1);
    }
    T top() const {
        if (len == 0) throw runtime_error("heap empty");
        return arr[0];
    }
    T pop() {
        if (len == 0) throw runtime_error("heap empty");
        T ret = arr[0];
        arr[0] = arr[--len];
        if (len > 0) heapifyDown(0);
        return ret;
    }
    int size() const { return len; }
    bool empty() const { return len == 0; }
    void buildFromArray(T a[], int n) {
        delete [] arr;
        cap = max(n, 1);
        arr = new T[cap];
        len = n;
        for (int i = 0; i < n; ++i) arr[i] = a[i];
        for (int i = (len/2)-1; i >= 0; --i) heapifyDown(i);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example usage: max-heap
    BinaryHeap<int> maxH(false);
    maxH.push(10); maxH.push(4); maxH.push(15); maxH.push(20);
    while (!maxH.empty()) {
        cout << maxH.pop() << (maxH.empty() ? '\n' : ' ');
    }

    // Example usage: min-heap
    BinaryHeap<int> minH(true);
    minH.push(10); minH.push(4); minH.push(15); minH.push(20);
    while (!minH.empty()) {
        cout << minH.pop() << (minH.empty() ? '\n' : ' ');
    }

    return 0;
}
