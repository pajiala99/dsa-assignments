#include <bits/stdc++.h>
using namespace std;
bool arraysEqualAsMultisets(int a[], int b[], int n) {
    unordered_map<int,int> fa, fb;
    for (int i = 0; i < n; ++i) fa[a[i]]++;
    for (int i = 0; i < n; ++i) fb[b[i]]++;
    if (fa.size() != fb.size()) return false;
    for (auto &p : fa) {
        int key = p.first;
        if (fb.find(key) == fb.end() || fb[key] != p.second) return false;
    }
    return true;
}
int main() {
    int a1[] = {1,2,5,4,0}, b1[] = {2,4,5,0,1};
    cout << (arraysEqualAsMultisets(a1, b1, 5) ? "true\n" : "false\n");
    int a2[] = {1,7,1}, b2[] = {7,7,1};
    cout << (arraysEqualAsMultisets(a2, b2, 3) ? "true\n" : "false\n"); 
    return 0;
}
