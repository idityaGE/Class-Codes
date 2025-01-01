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

TreeNode *insert(TreeNode *root, int val) {
  if (!root) {
    root = new TreeNode(val);
    return root;
  } else if (root->data > val) {
    root->left = insert(root->left, val);
  } else {
    root->right = insert(root->right, val);
  }
  return root;
}

TreeNode *delete_node(TreeNode *root, int val) {
  if (!root) return nullptr;
  if (root->data > val) {
    root->left = delete_node(root->left, val);
  } else if (root->data < val) {
    root->right = delete_node(root->right, val);
  } else {
    if (!root->left) {
      TreeNode *temp = root->right;
      delete root;
      return temp;
    } else if (!root->right) {
      TreeNode *temp = root->left;
      delete root;
      return temp;
    }

    TreeNode *parent = root;
    TreeNode *succ = root->right;
    while (succ->left) {
      parent = succ;
      succ = succ->left;
    }
    root->data = succ->data;
    if (parent != root) {
      parent->left = succ->right;
    } else {
      root->right = succ->right;
    }
    delete succ;
  }
  return root;
}

bool search(TreeNode *root, int val) {
  if (!root) return false;
  if (root->data == val) return true;
  if (root->data > val) {
    return search(root->left, val);
  } else {
    return search(root->right, val);
  }
}

void display(TreeNode *root) {
  if (!root) return;
  display(root->left);
  cout << root->data << " ";
  display(root->right);
}

void display_rec(TreeNode *root) {
  stack<TreeNode *> st;
  TreeNode *curr = root;
  while (curr != nullptr || !st.empty()) {
    while (curr != nullptr) {
      st.push(curr);
      curr = curr->left;
    }
    curr = st.top();
    st.pop();
    cout << curr->data << "  ";
    curr = curr->right;
  }
}

int main() {
  return 0;
}