#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void postorderIterative(Node* root) {
    if (root == NULL)
        return;

    stack<Node*> st1, st2;

    st1.push(root);

    while (!st1.empty()) {
        Node* curr = st1.top();
        st1.pop();

        st2.push(curr);

        if (curr->left)
            st1.push(curr->left);

        if (curr->right)
            st1.push(curr->right);
    }

    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Postorder Traversal: ";
    postorderIterative(root);

    return 0;
}