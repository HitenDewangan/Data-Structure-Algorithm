#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    int height;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), height(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* insertAVL(const vector<int>& items, int threshold) {
        if (items.empty())
            return nullptr;

        TreeNode* root = new TreeNode(items[0]);

        for (size_t idx = 1; idx < items.size(); ++idx) {
            root = insert(root, items[idx], threshold);
        }

        return root;
    }

    // Get the height of a node
    int Height(TreeNode* node) {
        return (node == nullptr) ? -1 : getHeightHelper(node);
    }


private:
    // Insert a key into the AVL tree rooted at 'node'
    TreeNode* insert(TreeNode* node, int key, int threshold) {
        if (!node)
            return new TreeNode(key);

        if (key < node->val) {
            node->left = insert(node->left, key, threshold);
        } else if (key > node->val) {
            node->right = insert(node->right, key, threshold);
        } else {
            // Duplicate keys are not allowed
            return node;
        }

        // Update height of the ancestor node
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Check for imbalance
        int balance = getBalance(node);

        // Balance the tree
        if (balance > threshold) {
            if (getBalance(node->left) >= 0) {
                return rightRotate(node);
            } else {
                return leftRightRotate(node);
            }
        } else if (balance < -threshold) {
            if (getBalance(node->right) <= 0) {
                return leftRotate(node);
            } else {
                return rightLeftRotate(node);
            }
        }

        return node;
    }

    // Get the height of a node
    int getHeight(TreeNode* node) {
        if (!node)
            return -1;
        return node->height;
    }

    // Helper function to get the height of a node
    int getHeightHelper(TreeNode* node) {
        if (!node) {
            return -1; // Base case: empty tree has height -1
        } else {
            // Recursively calculate the height of left and right subtrees
            int leftHeight = getHeightHelper(node->left);
            int rightHeight = getHeightHelper(node->right);

            // Return the maximum height + 1 for the current node
            return 1 + max(leftHeight, rightHeight);
        }
    }

    // Get the balance factor of a node
    int getBalance(TreeNode* node) {
        if (!node)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Right rotate subtree rooted with y
    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        // Return new root
        return x;
    }

    // Left rotate subtree rooted with x
    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        // Return new root
        return y;
    }

    // Left Right rotate subtree rooted with z
    TreeNode* leftRightRotate(TreeNode* z) {
        z->left = leftRotate(z->left);
        return rightRotate(z);
    }

    // Right Left rotate subtree rooted with z
    TreeNode* rightLeftRotate(TreeNode* z) {
        z->right = rightRotate(z->right);
        return leftRotate(z);
    }
};

// Helper function to print the binary tree in-order
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// find(key) : returns true if key is present else false in the tree
bool find(TreeNode* root, int key) {
    if (!root) return false;
    if (root->val == key) return true;
    if (key < root->val) return find(root->left, key);
    return find(root->right, key);
}

// insert(key) : inserts the key into the tree


// delete(key) : deletes the key from the tree

// order_of_key(key) : returns the order of the key compared to the existing elements i.e., how many elements are smaller than key 

// get_by_order(k) : returns the  k’th element among the existing keys


int main() {
    Solution solution;
    vector<int> items = {10, 20, 30, 40, 50, 25};
    int threshold = 1;

    TreeNode* root = solution.insertAVL(items, threshold);

    cout << "Inorder traversal of the constructed AVL tree: ";
    printInorder(root);
    cout << endl;

    // Height of the constructed AVL tree
    cout << "Height of the constructed AVL tree: " << solution.Height(root) << endl;

    // Inserting a new element in the same tree
    items.push_back(60);
    root = solution.insertAVL(items, threshold);

    cout << "Inorder traversal of the updated AVL tree: ";
    printInorder(root);
    cout << endl;

    // Height of the updated AVL tree
    cout << "Height of the updated AVL tree: " << solution.Height(root) << endl;

    items.push_back(70);
    root = solution.insertAVL(items, threshold);

    cout << "Inorder traversal of the updated AVL tree: ";
    printInorder(root);
    cout << endl;

    // FIND KEY
    cout<<"Finding 70 in the AVL tree: "<<find(root, 70)<<endl;
    cout<<"Finding 100 in the AVL tree: "<<find(root, 100)<<endl;

    return 0;
}
