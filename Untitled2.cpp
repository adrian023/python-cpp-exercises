#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(NULL), right(NULL) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

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

    TreeNode* findMinValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    TreeNode* deleteNode(TreeNode* root, int value) {
        if (root == NULL) {
            return root;
        } else if (value < root->value) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->value) {
            root->right = deleteNode(root->right, value);
        } else {
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* temp = findMinValueNode(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
        return root;
    }

    void preorderTraversal(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        cout << node->value << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorderTraversal(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->value << " ";
    }

    void levelorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->value << " ";

            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
    }

public:
    BinarySearchTree() : root(NULL) {}

    void insert(int value) {
        root = insertNode(root, value);
        cout << "Node " << value << " inserted." << endl;
        cout << "" << endl;        
        cout << "Preorder Traversal: ";
        preorderTraversal(root);
        cout << endl;
        cout << "Postorder Traversal: ";
        postorderTraversal(root);
        cout << endl;
        cout << "Levelorder Traversal: ";
        levelorderTraversal(root);
        cout << endl;
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
        cout << "Node " << value << " deleted." << endl;
        cout << "" << endl;
        cout << "Preorder Traversal: ";
        preorderTraversal(root);
        cout << endl;
        cout << "Postorder Traversal: ";
        postorderTraversal(root);
        cout << endl;
        cout << "Levelorder Traversal: ";
        levelorderTraversal(root);
        cout << endl;
    }
};

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

