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
    int cnt = 0;
    int ans = -1;

    void reverseInorder(TreeNode* root, int k) {
        if (root == NULL)
            return;

        reverseInorder(root->right, k);

        cnt++;
        if (cnt == k) {
            ans = root->val;
            return;
        }

        reverseInorder(root->left, k);
    }

    int kthLargest(TreeNode* root, int k) {
        reverseInorder(root, k);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    Solution obj;

    int k = 3;
    cout << "Kth Largest Element: " << obj.kthLargest(root, k) << endl;

    return 0;
}