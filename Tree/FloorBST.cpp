#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

int floorInBST(TreeNode* root, int key) {
    int floor = -1;

    while (root) {
        if (root->val == key) {
            floor = root->val;
            return floor;
        }

        if (key > root->val) {
            floor = root->val;
            root = root->right;
        } else {
            root = root->left;
        }
    }

    return floor;
}

int main() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);

    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    int key = 5;

    cout << floorInBST(root, key);

    return 0;
}