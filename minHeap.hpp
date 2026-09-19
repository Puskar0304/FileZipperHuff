#pragma once

#include <vector>
using namespace std;

class minHeap {
    vector<int> arr;
    int n = arr.size();

    void heapifyDown(int idx) {
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
            heapifyDown(smallest);
        }
    }

    void buildHeap() {
        for (int i = arr.size()/2 -1; i >= 0; i--) {
            heapifyDown(i);
        }
    }
};