#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    // Helper function to insert a value into the tree
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // Helper function to perform inorder traversal
    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    // Helper function to perform preorder traversal
    void preorderTraversal(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    // Helper function to perform postorder traversal
    void postorderTraversal(Node* node) {
        if (node != nullptr) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->data << " ";
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    // Public function to insert a value into the tree
    void insert(int value) {
        root = insert(root, value);
    }

    // Public function to perform inorder traversal
    void inorderTraversal() {
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }

    // Public function to perform preorder traversal
    void preorderTraversal() {
        cout << "Preorder Traversal: ";
        preorderTraversal(root);
        cout << endl;
    }

    // Public function to perform postorder traversal
    void postorderTraversal() {
        cout << "Postorder Traversal: ";
        postorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;

    // Insert values into the tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Perform traversals and print the values
    return 0;
}
