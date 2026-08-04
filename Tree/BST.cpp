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

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != NULL && root->val != val) {
            root = (val < root->val) ? root->left : root->right;
        }
        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;

    int val = 2;
    TreeNode* ans = obj.searchBST(root, val);

    if (ans != NULL)
        cout << "Found: " << ans->val << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}