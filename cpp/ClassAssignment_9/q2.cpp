#include <iostream>
#include <stack>
using namespace std;

class TreeNode {
 public:
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode()
      : data(0), left(nullptr), right(nullptr) {}
  TreeNode(int x)
      : data(x), left(nullptr), right(nullptr) {}
};

TreeNode *insert(TreeNode *root, int data) {
  if (!root) {
    TreeNode *temp = new TreeNode(data);
    return temp;
  }
  if (data < root->data)
    root->left = insert(root->left, data);
  else if (data > root->data)  // no duplicate allowed
    root->right = insert(root->right, data);
  return root;
}

bool search(TreeNode *root, int data) {
  if (!root) return false;
  if (root->data == data) return true;
  if (data < root->data)
    return search(root->left, data);
  else
    return search(root->right, data);
}

TreeNode *delete_Treenode(TreeNode *root, int x) {
  if (!root) return nullptr;
  if (root->data > x) {
    root->left = delete_Treenode(root->left, x);
    return root;
  } else if (root->data < x) {
    root->right = delete_Treenode(root->right, x);
    return root;
  } else {
    // leaf Treenode
    if (!root->left && !root->right) {
      delete root;
      return nullptr;
    }
    // on child exist
    else if (!root->right) {
      TreeNode *temp = root->left;
      delete root;
      return temp;
    } else if (!root->left) {
      TreeNode *temp = root->right;
      delete root;
      return temp;
    }
    // both child exist
    else {
      TreeNode *child = root->left;
      TreeNode *parent = root;
      while (child->right) {
        parent = child;
        child = child->right;
      }
      if (root != parent) {
        parent->right = child->left;
        child->left = root->left;
        child->right = root->right;
        delete root;
        return child;
      }
      child->right = root->right;
      delete root;
      return child;
    }
  }
}

void display_non_rec(TreeNode *root) {
  stack<TreeNode *> st;
  TreeNode *current = root;
  while (current != nullptr || !st.empty()) {
    while (current != nullptr) {
      st.push(current);
      current = current->left;
    }
    current = st.top();
    st.pop();
    cout << current->data << "  ";
    current = current->right;
  }
}

void display(TreeNode *root) {
  if (!root) return;
  display(root->left);
  cout << root->data << "  ";
  display(root->right);
}

int main() {
  TreeNode *root = nullptr;
  root = insert(root, 4);
  root = insert(root, 5);
  root = insert(root, 14);
  root = insert(root, 8);
  root = insert(root, 34);
  root = insert(root, 24);
  root = insert(root, 3);
  root = insert(root, 32);
  root = insert(root, 2);
  root = insert(root, 8);
  cout << "Inorder Traversal: ";
  display(root);
  cout << endl;
  cout << "search 8: ";
  cout << search(root, 8);
  cout << endl;
  delete_Treenode(root, 8);
  delete_Treenode(root, 8);
  delete_Treenode(root, 14);
  cout << "Non-recursive Inorder Traversal after deletion: ";
  display_non_rec(root);
  cout << endl;
  cout << "search 8: ";
  cout << search(root, 8);
}