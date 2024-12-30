#include <iostream>
using namespace std;

class TNode {
public:
    int data;
    TNode* left;
    TNode* right;

    TNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
public:
    TNode* root;

    BinaryTree() {
        root = nullptr;
    }

    // Function to insert a new node in the binary tree
    void insert(int value) {
        TNode* newNode = new TNode(value);
        if (root == nullptr) {
            root = newNode;
        }
        else {
            insertRec(root, newNode); // Call the recursive insert function
        }
    }

private:
    // Recursive function to insert a new node
    void insertRec(TNode* current, TNode* newNode) {
        if (current->left == nullptr) {
            current->left = newNode; // Insert as left child if available
        }
        else if (current->right == nullptr) {
            current->right = newNode; // Insert as right child if available
        }
        else {
            // Recur down the left subtree first
            insertRec(current->left, newNode);
        }
    }

public:
    // Function to count leaf nodes
    int count_leaf(TNode* node) {
        if (node == nullptr)
            return 0; 
        if (node->left == nullptr && node->right == nullptr) {
            cout << "Leaf node found: " << node->data << endl; // Print leaf node
            return 1; 
        }
        return count_leaf(node->left) + count_leaf(node->right); // Recursive count
    }

    // Function to count non-leaf nodes
    int count_nonleaf(TNode* node) {
        if (node == nullptr)
            return 0;
        if (node->left != nullptr || node->right != nullptr) {
            return 1 + count_nonleaf(node->left) + count_nonleaf(node->right); // Count this node and recurse
        }
        return count_nonleaf(node->left) + count_nonleaf(node->right); // Only recurse if it's a leaf
    }

    // Function to check if a value is a leaf node
    bool isleaf(TNode* node, int value) {
        if (node == nullptr)
            return false;
        if (node->data == value && node->left == nullptr && node->right == nullptr)
            return true; 
        return isleaf(node->left, value) || isleaf(node->right, value); // Recurse for both children
    }

    // Function to print the tree in inorder traversal (for testing)
    void inorder(TNode* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main() {
    BinaryTree tree;

    // Inserting nodes into the binary tree as per your structure
    tree.insert(14);
    tree.insert(4);
    tree.insert(15);
    tree.insert(3);
    tree.insert(9);

    // Continuing with deeper levels as per your original structure:
    tree.insert(14);  // Left child of 15
    tree.insert(18);  // Right child of 15

    tree.insert(7);   // Left child of 9
    tree.insert(9);   // Right child of 9

    tree.insert(16);  // Left child of 18
    tree.insert(20);  // Right child of 18

    tree.insert(5);   // Left child of 7
    tree.insert(17);  // Right child of 16
    tree.insert(4);   // Right child of 16 (this will be a new node)

    cout << "\nInorder Traversal of the Binary Tree: ";
    tree.inorder(tree.root);

    cout << endl;

    int leafCount = tree.count_leaf(tree.root);
    int nonLeafCount = tree.count_nonleaf(tree.root);

    cout << "Number of leaf nodes: " << leafCount << endl;
    cout << "Number of non-leaf nodes: " << nonLeafCount << endl;

    int valueToCheck = 5; 
    bool isLeafValue = tree.isleaf(tree.root, valueToCheck);

    cout << "Is " << valueToCheck << " a leaf? " << (isLeafValue ? "Yes" : "No") << endl;

    return 0;
}
