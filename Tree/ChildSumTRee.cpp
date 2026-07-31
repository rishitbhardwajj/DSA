#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    void reorder(Node* root) {
        if (root == NULL)
            return;

        int child = 0;

        if (root->left)
            child += root->left->data;

        if (root->right)
            child += root->right->data;

        if (child >= root->data)
            root->data = child;
        else {
            if (root->left)
                root->left->data = root->data;
            else if (root->right)
                root->right->data = root->data;
        }

        reorder(root->left);
        reorder(root->right);

        int tot = 0;

        if (root->left)
            tot += root->left->data;

        if (root->right)
            tot += root->right->data;

        if (root->left || root->right)
            root->data = tot;
    }
};

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(40);

    root->left = new Node(10);
    root->right = new Node(20);

    root->left->left = new Node(2);
    root->left->right = new Node(5);

    root->right->left = new Node(30);
    root->right->right = new Node(40);

    Solution obj;

    obj.reorder(root);

    inorder(root);

    return 0;
}