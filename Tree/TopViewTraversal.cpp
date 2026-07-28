#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// Definition of Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<int> topView(Node* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;

        map<int, int> mpp;
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int line = it.second;

            if (mpp.find(line) == mpp.end())
                mpp[line] = node->data;

            if (node->left != NULL)
                q.push({node->left, line - 1});

            if (node->right != NULL)
                q.push({node->right, line + 1});
        }

        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {
    /*
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
                \
                 8

    Top View: 4 2 1 3 7
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->right->left->right = new Node(8);

    Solution obj;
    vector<int> ans = obj.topView(root);

    cout << "Top View: ";
    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}