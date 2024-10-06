#include <iostream>
#include <queue>

using namespace std;

// Structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function for Breadth-First Traversal (BFS)
void breadthFirstTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Create a queue to hold nodes to be visited
    queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        // Get the front node in the queue
        TreeNode* current = queue.front();
        queue.pop();

        // Print the data of the node
        cout << current->data << " ";

        // Enqueue left child
        if (current->left != nullptr) {
            queue.push(current->left);
        }

        // Enqueue right child
        if (current->right != nullptr) {
            queue.push(current->right);
        }
    }
}

int main() {
    // Creating a simple binary tree:
    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Perform BFS traversal
    cout << "Breadth-First Traversal: ";
    breadthFirstTraversal(root);

    return 0;
}
