#pragma once

#include <bits/stdc++.h>
#include "minHeap.hpp"

class huffman {
    unordered_map<char, int> mp;
    unordered_map<char, string> codes;
    string s;
    minHeap heap;

    void input() {
        cout << "Enter the input: ";
        cin >> s;
    }

    void count(string s) {
        for (auto it : s) {
            mp[it]++;
        }
    }    

    void createNode() {
        for (auto it : mp) {
            Node* node = new Node;
            node->c = it.first;
            node->freq = it.second;
            node->left = nullptr;
            node->right = nullptr;
            heap.insert(node);
        }
    }

    void build() {
        Node* a = heap.extractMin();
        Node* b = heap.extractMin();
        Node* parent = new Node;
        parent -> freq = a -> freq + b -> freq;
        parent -> left = a;
        parent -> right = b;
        heap.insert(parent);
    }

    void buildTree() {
        while(heap.size() > 1) {
            build();
        }
    }

    void createTree(Node* root, string code) {
        if (root == nullptr) {
            return;
        }
        if (root -> left == nullptr && root -> right == nullptr) {
            codes[root -> c] = code;
        }
        createTree(root -> left, code + "0");
        createTree(root -> right, code + "1");
    }

};