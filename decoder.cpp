#include "huffman.hpp"

class Decoder {
    public:
        string decode(Node* root, string encoded) {
            Node* curr = root;
            string ans;
            for (auto it : encoded) {
                if (it == '0') {
                    curr = curr -> left;
                }
                else {
                    curr = curr -> right;
                }
                if (curr -> left == nullptr && curr -> right == nullptr) {
                    ans += curr -> c;
                    curr = root;
                }
            }
            return ans;
        }
};

int main() {
    huffman hf;
    hf.compress();
    string encoded = hf.getString();
    string actual = hf.getInput();
    cout << "Actual: " << actual << endl;
    Decoder decoder;
    string decoded = decoder.decode(hf.getRoot(), encoded);
    cout << "Decoded: " << decoded << endl;
    return 0;
}