#include "huffman.hpp"

int main() {
    huffman huff;
    huff.compress();
    unordered_map<char, string> mp = huff.getCode();
    for (auto it : mp) {
        cout << it.first << ": " << it.second << "\n";
    }
    return 0;
} 