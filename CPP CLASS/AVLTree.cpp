#include <iostream>
#include <algorithm> // For max function

// Define the structure for AVL tree nodes
struct AVLNode {
    int data;
    AVLNode *left;
    AVLNode *right;
    int height;

    AVLNode(int d) : data(d), left(nullptr), right(nullptr), height(1) {}
};

// AVL Tree class
class AVLTree {
public:
    AVLNode* root;

    AVLTree() : root(nullptr) {}

    // Function to insert a new key in the subtree rooted with node and
    // returns the new root of the subtree.
    AVLNode* insert(AVLNode* node, int key) {
        if (node == nullptr)
            return new AVLNode(key);

        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else // Equal keys are not allowed in the AVL tree
            return node;

        // Update height of this ancestor node
        node->height = 1 + std::max(height(node->left), height(node->right));

        // Check whether this node became unbalanced
        int balance = getBalance(node);

        // If this node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && key < node->left->data)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->data)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        /* return the (unchanged) node pointer */
        return node;
    }

    // A utility function to get the height of the tree
    int height(AVLNode *N) {
        if (N == nullptr)
            return 0;
        return N->height;
    }

    // A utility function to get the balance factor of a node
    int getBalance(AVLNode *N) {
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }

    // Right rotate subtree rooted with y
    AVLNode* rightRotate(AVLNode *y) {
        AVLNode *x = y->left;
        AVLNode *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        // Return new root
        return x;
    }

    // Left rotate subtree rooted with x
    AVLNode* leftRotate(AVLNode *x) {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        // Return new root
        return y;
    }

    // Utility function to print preorder traversal of the tree.
    // The function also prints height of every node
    void preOrder(AVLNode *root) {
        if(root != nullptr) {
            std::cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
};

// Main function to test above functions
int main() {
    AVLTree tree;

    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 25);

    std::cout << "Preorder traversal of the constructed AVL tree is \n";
    tree.preOrder(tree.root);

    return 0;
}
