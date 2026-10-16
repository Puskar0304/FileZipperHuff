#include "huffman.hpp"

int main() {
    huffman huff;
    huff.input();
    string file = huff.getInput();
    ifstream fin(file);
    if (!fin) {
        cout << "File cannot be opened";
        return 1;
    }
    
    huff.compress();
    unordered_map<char, string> mp = huff.getCode();
    for (auto it : mp) {
        cout << it.first << ": " << it.second << "\n";
    }
    string encoded;
    encoded = huff.getString();
    cout << encoded << endl;
    return 0;

} 