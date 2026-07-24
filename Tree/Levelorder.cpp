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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};

int main() {
    int a, b, c, d, e;

    cout << "Enter root: ";
    cin >> a;
    cout << "Enter left child of root: ";
    cin >> b;
    cout << "Enter right child of root: ";
    cin >> c;
    cout << "Enter left child of " << b << ": ";
    cin >> d;
    cout << "Enter right child of " << b << ": ";
    cin >> e;

    TreeNode* root = new TreeNode(a);
    root->left = new TreeNode(b);
    root->right = new TreeNode(c);
    root->left->left = new TreeNode(d);
    root->left->right = new TreeNode(e);

    Solution obj;
    vector<vector<int>> ans = obj.levelOrder(root);

    cout << "\nLevel Order Traversal:\n";
    for (auto level : ans) {
        for (int x : level)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}