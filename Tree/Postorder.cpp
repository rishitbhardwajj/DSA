#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* buildTree() {
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    Node* root = createNode(x);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = buildTree();

    cout << "Postorder Traversal: ";
    postorder(root);

    return 0;
}