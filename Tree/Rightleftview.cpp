#include <iostream>
#include <vector>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }

    void recursion(TreeNode* root, int level, vector<int>& res) {
        if (root == NULL)
            return;

        if (res.size() == level)
            res.push_back(root->val);

        recursion(root->right, level + 1, res);
        recursion(root->left, level + 1, res);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution obj;

    vector<int> ans = obj.rightSideView(root);

    for (int x : ans)
        cout << x << " ";

    return 0;
}