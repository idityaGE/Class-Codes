#include <iostream>
#include <stack>
using namespace std;

// Node structure for Binary Search Tree
struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int value) {
    data = value;
    left = right = nullptr;
  }
};

// Class representing the Binary Search Tree
class BST {
 private:
  TreeNode* root;

  // Helper function for recursive inorder traversal
  void inorderRecursive(TreeNode* node) {
    if (node != nullptr) {
      inorderRecursive(node->left);
      cout << node->data << " ";
      inorderRecursive(node->right);
    }
  }

  // Helper function for deleting a node
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root;

    // Traverse to find the node to be deleted
    if (key < root->data) {
      root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
      root->right = deleteNode(root->right, key);
    } else {
      // Node found
      if (root->left == nullptr) {
        TreeNode* temp = root->right;
        delete root;
        return temp;
      } else if (root->right == nullptr) {
        TreeNode* temp = root->left;
        delete root;
        return temp;
      }

      // Node with two children, find inorder successor
      TreeNode* temp = minValueNode(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
    return root;
  }

  // Helper function to find minimum value node (for deletion)
  TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != nullptr) {
      current = current->left;
    }
    return current;
  }

 public:
  BST() {
    root = nullptr;
  }

  // Function to insert a key into BST
  void insert(int key) {
    TreeNode* newNode = new TreeNode(key);
    if (root == nullptr) {
      root = newNode;
      return;
    }

    TreeNode* current = root;
    TreeNode* parent = nullptr;
    while (current != nullptr) {
      parent = current;
      if (key < current->data) {
        current = current->left;
      } else {
        current = current->right;
      }
    }

    if (key < parent->data) {
      parent->left = newNode;
    } else {
      parent->right = newNode;
    }
  }

  // Function to search for a key in BST
  bool search(int key) {
    TreeNode* current = root;
    while (current != nullptr) {
      if (key == current->data) {
        return true;
      } else if (key < current->data) {
        current = current->left;
      } else {
        current = current->right;
      }
    }
    return false;
  }

  // Function to perform recursive inorder traversal
  void inorderRecursive() {
    inorderRecursive(root);
    cout << endl;
  }

  // Function to perform non-recursive inorder traversal using a stack
  void inorderNonRecursive() {
    stack<TreeNode*> st;
    TreeNode* current = root;

    while (current != nullptr || !st.empty()) {
      while (current != nullptr) {
        st.push(current);
        current = current->left;
      }

      current = st.top();
      st.pop();
      cout << current->data << " ";

      current = current->right;
    }
    cout << endl;
  }

  // Function to delete a key from BST
  void deleteKey(int key) {
    root = deleteNode(root, key);
  }
};

int main() {
  BST bst;

  // Inserting elements into BST
  bst.insert(50);
  bst.insert(30);
  bst.insert(20);
  bst.insert(40);
  bst.insert(70);
  bst.insert(60);
  bst.insert(80);

  cout << "Inorder traversal (Recursive): ";
  bst.inorderRecursive();

  cout << "Inorder traversal (Non-recursive): ";
  bst.inorderNonRecursive();

  // Searching for an element
  int keyToSearch = 40;
  if (bst.search(keyToSearch)) {
    cout << "Key " << keyToSearch << " found in the BST." << endl;
  } else {
    cout << "Key " << keyToSearch << " not found in the BST." << endl;
  }

  // Deleting a node
  int keyToDelete = 50;
  bst.deleteKey(keyToDelete);
  cout << "Inorder traversal after deleting " << keyToDelete << ": ";
  bst.inorderRecursive();

  return 0;
}
