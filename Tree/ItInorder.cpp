#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> inorder;

        while (true) {
            if (node != NULL) {
                st.push(node);
                node = node->left;
            }
            else {
                if (st.empty())
                    break;

                node = st.top();
                st.pop();

                inorder.push_back(node->val);
                node = node->right;
            }
        }

        return inorder;
    }
};

int main() {
    // Creating the binary tree
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;
    vector<int> ans = obj.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int x : ans)
        cout << x << " ";

    return 0;
}