#include <bits/stdc++.h>
using namespace std;
void heapifyDown(vector<int>& arr, int n, int idx) {
    int smallest = idx;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    if (l < n && arr[smallest] > arr[l]) {
        smallest = l;
    }
    if (r < n && arr[smallest] > arr[r]) {
        smallest = r;
    }
    if (smallest != idx) {
        swap(arr[smallest], arr[idx]);
        heapifyDown(arr, n, smallest);
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = n/2 -1; i >= 0; i--) {
        heapifyDown(arr, n, i);
    }
}