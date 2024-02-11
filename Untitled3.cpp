#include <iostream>
#include <queue>

using namespace std;

// TreeNode structure represents a node in the binary search tree
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(NULL), right(NULL) {}
};

// BinarySearchTree class implements the binary search tree operations
class BinarySearchTree {
private:
    TreeNode* root; // Pointer to the root node of the tree

    // Private helper function to insert a node recursively
    TreeNode* insertNode(TreeNode* root, int value) {
        if (root == NULL) {
            root = new TreeNode(value);
        } else if (value < root->value) {
            root->left = insertNode(root->left, value);
        } else {
            root->right = insertNode(root->right, value);
        }
        return root;
    }

    // Private helper function to find the node with the minimum value in a subtree
    TreeNode* findMinValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    // Private helper function to delete a node recursively
    TreeNode* deleteNode(TreeNode* root, int value) {
        if (root == NULL) {
            return root;
        } else if (value < root->value) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->value) {
            root->right = deleteNode(root->right, value);
        } else {
            // Node to be deleted has been found

            // Case 1: Node has no children or only one child
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 2: Node has two children
            TreeNode* temp = findMinValueNode(root->right); // Find the minimum value in the right subtree
            root->value = temp->value; // Replace the value of the node to be deleted with the minimum value
            root->right = deleteNode(root->right, temp->value); // Delete the node with the minimum value from the right subtree
        }
        return root;
    }

    // Private helper function to perform preorder traversal recursively
    void preorderTraversal(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        cout << node->value << " "; // Display the value of the current node
        preorderTraversal(node->left); // Recursively traverse the left subtree
        preorderTraversal(node->right); // Recursively traverse the right subtree
    }

    // Private helper function to perform postorder traversal recursively
    void postorderTraversal(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        postorderTraversal(node->left); // Recursively traverse the left subtree
        postorderTraversal(node->right); // Recursively traverse the right subtree
        cout << node->value << " "; // Display the value of the current node
    }

    // Private helper function to perform level-order traversal using a queue
    void levelorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->value << " "; // Display the value of the current node

            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
    }

public:
    // Public constructor to initialize the BinarySearchTree object
    BinarySearchTree() : root(NULL) {}

    // Public function to insert a node into the tree
    void insert(int value) {
        root = insertNode(root, value);
        cout << "Node " << value << " inserted." << endl;
        cout << "" << endl;
        cout << "Preorder Traversal: ";
        preorderTraversal(root); // Display the tree in preorder traversal
        cout << endl;
        cout << "Postorder Traversal: ";
        postorderTraversal(root); // Display the tree in postorder traversal
        cout << endl;
        cout << "Levelorder Traversal: ";
        levelorderTraversal(root); // Display the tree in level-order traversal
        cout << endl;
    }

    // Public function to delete a node from the tree
    void deleteNode(int value) {
        root = deleteNode(root, value);
        cout << "Node " << value << " deleted." << endl;
        cout << "" << endl;
        cout << "Preorder Traversal: ";
        preorderTraversal(root); // Display the tree in preorder traversal
        cout << endl;
        cout << "Postorder Traversal: ";
        postorderTraversal(root); // Display the tree in postorder traversal
        cout << endl;
        cout << "Levelorder Traversal: ";
        levelorderTraversal(root); // Display the tree in level-order traversal
        cout << endl;
    }
};

// The main function to run the program
int main() {
    BinarySearchTree bst;

    int choice;
    bool exitProgram = false;

    while (!exitProgram) {
        cout << "" << endl;
        cout << "Enter your choice:" << endl;
        cout << "1. Insert a node" << endl;
        cout << "2. Delete a node" << endl;
        cout << "3. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        int nodeValue;
        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> nodeValue;
                bst.insert(nodeValue);
                break;
            case 2:
                cout << "Enter the value to delete: ";
                cin >> nodeValue;
                bst.deleteNode(nodeValue);
                break;
            case 3:
                exitProgram = true;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }

    return 0;
}

