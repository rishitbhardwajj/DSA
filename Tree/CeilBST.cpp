#include <iostream>
using namespace std;

struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int findCeil(BinaryTreeNode* root, int key) {
    int ceil = -1;

    while (root) {
        if (root->data == key) {
            ceil = root->data;
            return ceil;
        }

        if (key > root->data) {
            root = root->right;
        } else {
            ceil = root->data;
            root = root->left;
        }
    }

    return ceil;
}

int main() {
    BinaryTreeNode* root = new BinaryTreeNode(8);
    root->left = new BinaryTreeNode(4);
    root->right = new BinaryTreeNode(12);

    root->left->left = new BinaryTreeNode(2);
    root->left->right = new BinaryTreeNode(6);

    root->right->left = new BinaryTreeNode(10);
    root->right->right = new BinaryTreeNode(14);

    int key = 5;

    cout << findCeil(root, key);

    return 0;
}