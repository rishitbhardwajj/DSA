#include <iostream>
#include <vector>
#include <stack>
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

vector<int> postOrder(Node* root) {
    vector<int> ans;

    if (root == NULL)
        return ans;

    stack<Node*> st;
    Node* curr = root;

    while (curr != NULL || !st.empty()) {

        if (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            Node* temp = st.top()->right;

            if (temp == NULL) {
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);

                while (!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else {
                curr = temp;
            }
        }
    }

    return ans;
}

int main() {
    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = postOrder(root);

    cout << "Postorder Traversal: ";
    for (int x : ans)
        cout << x << " ";

    return 0;
}