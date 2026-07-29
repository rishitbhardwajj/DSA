#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

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
    vector<int> bottomView(Node* root) {
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

            mpp[line] = node->data;

            if (node->left != NULL) {
                q.push({node->left, line - 1});
            }

            if (node->right != NULL) {
                q.push({node->right, line + 1});
            }
        }

        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {
    Node* root = new Node(20);

    root->left = new Node(8);
    root->right = new Node(22);

    root->left->left = new Node(5);
    root->left->right = new Node(3);

    root->right->left = new Node(4);
    root->right->right = new Node(25);

    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    Solution obj;
    vector<int> ans = obj.bottomView(root);

    for (int x : ans)
        cout << x << " ";

    return 0;
}