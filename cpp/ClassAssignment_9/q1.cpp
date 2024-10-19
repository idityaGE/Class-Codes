#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Node structure to represent a tree node
struct TreeNode {
  int data;
  vector<TreeNode*> children;  // Vector to hold children, as the order is unknown

  // Constructor to initialize a node
  TreeNode(int value) {
    data = value;
  }
};

// Class representing the Tree
class Tree {
 private:
  TreeNode* root;                         // Root node of the tree
  unordered_map<int, TreeNode*> nodeMap;  // For quick access to nodes by their values

 public:
  Tree() {
    root = nullptr;
  }

  // Function to add a node as a child of a specific parent node
  void addNode(int parentValue, int childValue) {
    TreeNode* newNode = new TreeNode(childValue);

    // If it's the first node, set it as the root
    if (!root) {
      root = newNode;
      nodeMap[childValue] = newNode;
      cout << "Node " << childValue << " added as the root." << endl;
      return;
    }

    // Find the parent node
    if (nodeMap.find(parentValue) != nodeMap.end()) {
      TreeNode* parentNode = nodeMap[parentValue];
      parentNode->children.push_back(newNode);
      nodeMap[childValue] = newNode;  // Add new node to map
      cout << "Node " << childValue << " added as a child of " << parentValue << "." << endl;
    } else {
      cout << "Parent node " << parentValue << " not found." << endl;
    }
  }

  // Function to display the tree in level order
  void displayLevelOrder() {
    if (!root) {
      cout << "Tree is empty." << endl;
      return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode* current = q.front();
      q.pop();
      cout << current->data << " ";

      // Add all children to the queue
      for (TreeNode* child : current->children) {
        q.push(child);
      }
    }
    cout << endl;
  }
};

int main() {
  Tree tree;

  tree.addNode(-1, 1);  // Adding root node
  tree.addNode(1, 2);
  tree.addNode(1, 3);
  tree.addNode(2, 4);
  tree.addNode(2, 5);
  tree.addNode(3, 6);
  tree.addNode(3, 7);

  cout << "Tree in level order: ";
  tree.displayLevelOrder();

  return 0;
}
