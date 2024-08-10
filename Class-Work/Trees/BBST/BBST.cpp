#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// BBST class implementation
class BBST {
private:
    Node* root;

    // Helper function to find the minimum value node in a subtree
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Helper function to perform right rotation in the BBST
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        return x;
    }

    // Helper function to perform left rotation in the BBST
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        return y;
    }

    // Get the height of a subtree
    int getHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

    // Get the balance factor of a node
    int getBalance(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

public:
    BBST() {
        root = nullptr;
    }

    // Insert a new node into the BBST
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Recursive helper function for insertion
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        } else { // Duplicate values not allowed (modify if needed)
            cout << "Duplicate value (" << value << ") ignored." << endl;
        }

        // Maintain balance after insertion
        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && value < node->left->data) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && value > node->right->data) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Search for a node with a given value
    bool search(int value) {
        return searchRec(root, value);
    }

    // Recursive helper function for search
    Node* searchRec(Node* node, int value) {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return searchRec(node->left, value);
        } else {
            return searchRec(node->right, value);
        }
    }

    // Delete a node with a given value (maintain balance)
    Node* deleteNode(Node* root, int value) {
        // 1. Base Case: If the tree is empty
        if (root == nullptr) {
            return root;
        }

        // 2. Search for the node to be deleted
        if (value < root->data) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->data) {
            root->right = deleteNode(root->right, value);
        } else {
            // 3. Node found: Handle deletion cases
            // 3.1. Node with one child or no child
            if (root->left == nullptr || root->right == nullptr) {
                Node* temp = root->left ? root->left : root->right;

                // Free the memory of the deleted node
                if (temp == nullptr) {
                    delete root;
                    root = nullptr;
                } else { // Copy the child's content to the parent and delete the child
                    *root = *temp;
                    delete temp;
                }
            } else {
                // 3.2. Node with two children
                // Find the in-order successor (minimum value in right subtree)
                Node* temp = minValueNode(root->right);

                // Copy the in-order successor's data to the current node
                root->data = temp->data;

                // Recursively delete the in-order successor (now it has at most one child)
                root->right = deleteNode(root->right, temp->data);
            }
        }

            // 4. Maintain balance after deletion
            int balance = getBalance(root);

            // Left Left Case
            if (balance > 1 && getBalance(root->left) >= 0) {
                return rightRotate(root);
            }

            // Left Right Case
            if (balance > 1 && getBalance(root->left) < 0) {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }

            // Right Right Case
            if (balance < -1 && getBalance(root->right) <= 0) {
                return leftRotate(root);
            }

            // Right Left Case
            if (balance < -1 && getBalance(root->right) > 0) {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }

            return root;
    }

};
