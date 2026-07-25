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

void preInPostTraversal(TreeNode* root) {

    if (root == NULL)
        return;

    vector<int> pre, in, post;

    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {

        auto it = st.top();
        st.pop();

        // Preorder
        if (it.second == 1) {

            pre.push_back(it.first->val);
            it.second++;
            st.push(it);

            if (it.first->left)
                st.push({it.first->left, 1});
        }

        // Inorder
        else if (it.second == 2) {

            in.push_back(it.first->val);
            it.second++;
            st.push(it);

            if (it.first->right)
                st.push({it.first->right, 1});
        }

        // Postorder
        else {

            post.push_back(it.first->val);
        }
    }

    cout << "Preorder : ";
    for (int x : pre)
        cout << x << " ";

    cout << "\nInorder  : ";
    for (int x : in)
        cout << x << " ";

    cout << "\nPostorder: ";
    for (int x : post)
        cout << x << " ";
}

int main() {

    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    preInPostTraversal(root);

    return 0;
}