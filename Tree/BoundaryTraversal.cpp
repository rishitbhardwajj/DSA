#include <iostream>
#include <vector>
using namespace std;

// Definition of Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    bool isLeaf(Node* root) {
        return (root->left == NULL && root->right == NULL);
    }

    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* cur = root->left;
        while (cur) {
            if (!isLeaf(cur))
                res.push_back(cur->data);

            if (cur->left)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }

    void addRightBoundary(Node* root, vector<int>& res) {
        Node* cur = root->right;
        vector<int> tmp;

        while (cur) {
            if (!isLeaf(cur))
                tmp.push_back(cur->data);

            if (cur->right)
                cur = cur->right;
            else
                cur = cur->left;
        }

        for (int i = tmp.size() - 1; i >= 0; i--) {
            res.push_back(tmp[i]);
        }
    }

    void addLeaves(Node* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }

        if (root->left)
            addLeaves(root->left, res);

        if (root->right)
            addLeaves(root->right, res);
    }

    vector<int> printBoundary(Node* root) {
        vector<int> res;

        if (!root)
            return res;

        if (!isLeaf(root))
            res.push_back(root->data);

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};

int main() {
    /*
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
           / \
          8   9

    Boundary Traversal:
    1 2 4 8 9 6 7 3
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    Solution obj;
    vector<int> ans = obj.printBoundary(root);

    cout << "Boundary Traversal: ";
    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}