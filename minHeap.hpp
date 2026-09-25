#pragma once

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char c;
    int freq;
    Node* left;
    Node* right;
};

class minHeap {
    vector<Node*> arr;

    void heapifyDown(int idx) {
        int n = arr.size();
        int smallest = idx;
        int l = 2 * idx + 1;
        int r = 2 * idx + 2;
        if (l < n && arr[smallest]->freq > arr[l]->freq) {
            smallest = l;
        }
        if (r < n && arr[smallest]->freq > arr[r]->freq) {
            smallest = r;
        }
        if (smallest != idx) {
            swap(arr[smallest], arr[idx]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int idx) {
        if (idx == 0) {
            return ;
        }
        int par = (idx - 1) / 2;
        if (arr[par]->freq > arr[idx]->freq) {
            swap(arr[idx], arr[par]);
            heapifyUp(par);
        }
    }

    void buildHeap() {
        for (int i = arr.size()/2 -1; i >= 0; i--) {
            heapifyDown(i);
        }
    }
    public:

        int size() {
            return arr.size();
        }
    
        void insert(Node* n) {
            arr.push_back(n);
            heapifyUp(arr.size() - 1);
        }

        Node* extractMin() {
            Node* mini = arr[0];
            arr[0] = arr.back();
            arr.pop_back();
            if(!arr.empty()) {
                heapifyDown(0);
            }
            return mini;
        }
};