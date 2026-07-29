#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(NULL), right(NULL) {}

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) {
        val = x;
        this->left = left;
        this->right = right;
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isSymmetricHelp(root->left, root->right);
    }

    bool isSymmetricHelp(TreeNode* left, TreeNode* right) {
        if (left == NULL || right == NULL)
            return left == right;

        if (left->val != right->val)
            return false;

        return isSymmetricHelp(left->left, right->right) &&
               isSymmetricHelp(left->right, right->left);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution obj;

    if (obj.isSymmetric(root))
        cout << "Tree is Symmetric" << endl;
    else
        cout << "Tree is Not Symmetric" << endl;

    return 0;
}