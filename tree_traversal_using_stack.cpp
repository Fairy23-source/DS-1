
#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createTree() {
    int value;
    cout << "Enter value (-1 for no node): ";
    cin >> value;

    if (value == -1)
        return NULL;

    Node* root = new Node;
    root->data = value;

    cout << "Left child of " << value << endl;
    root->left = createTree();

    cout << "Right child of " << value << endl;
    root->right = createTree();

    return root;
}

void inorder(Node* root) {
    stack<Node*> s;
    Node* curr = root;

    while (curr != NULL || !s.empty()) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        cout << curr->data << " ";
        curr = curr->right;
    }
}

int main() {
    Node* root = createTree();

    cout << "\nInorder Traversal: ";
    inorder(root);

    return 0;
}
