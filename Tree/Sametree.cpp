#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) {
            return (p == q);
        }

        return (p->val == q->val)
            && isSameTree(p->left, q->left)
            && isSameTree(p->right, q->right);
    }
};

int main() {
    // Creating first tree
    //       1
    //      / \
    //     2   3
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Creating second tree
    //       1
    //      / \
    //     2   3
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution obj;

    if (obj.isSameTree(p, q))
        cout << "Both trees are the same." << endl;
    else
        cout << "Both trees are different." << endl;

    return 0;
}