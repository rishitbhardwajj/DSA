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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;

        if (root == NULL)
            return preorder;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            root = st.top();
            st.pop();

            preorder.push_back(root->val);

            if (root->right != NULL)
                st.push(root->right);

            if (root->left != NULL)
                st.push(root->left);
        }

        return preorder;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;
    vector<int> ans = obj.preorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int x : ans)
        cout << x << " ";

    return 0;
}