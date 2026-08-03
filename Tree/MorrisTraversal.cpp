#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

vector<int> getPreorder(TreeNode* root) {
    vector<int> preorder;
    TreeNode* cur = root;

    while (cur != NULL) {

        if (cur->left == NULL) {
            preorder.push_back(cur->val);
            cur = cur->right;
        }
        else {
            TreeNode* prev = cur->left;

            while (prev->right && prev->right != cur) {
                prev = prev->right;
            }

            if (prev->right == NULL) {
                prev->right = cur;
                preorder.push_back(cur->val);
                cur = cur->left;
            }
            else {
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }

    return preorder;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> preorder = getPreorder(root);

    cout << "Preorder Traversal: ";
    for (int x : preorder) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}