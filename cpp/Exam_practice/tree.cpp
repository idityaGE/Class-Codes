#include <iostream>
#include <queue>
using namespace std;

class Node {
 public:
  int data;
  Node *child;
  Node *siblling;
  Node(int val)
      : data(val), child(nullptr), siblling(nullptr) {}
};

class Tree {
 private:
  Node *root;

 public:
  Tree()
      : root(nullptr) {}

  void create(int val) {
    if (root == nullptr) root = new Node(val);
  }

  void insert_child(int parentData, int childData) {
    Node *parentNode = search(root, parentData);
    if (parentNode) {
      Node *temp = parentNode;
      while (temp) {
        if (temp->data == childData) {
          cout << "Child " << childData << " already exists under parent " << parentData << endl;
          return;
        }
        temp = temp->siblling;
      }

      Node *newNode = new Node(childData);
      if (parentNode->child == nullptr) {
        parentNode->child = newNode;
      } else {
        temp = parentNode->child;
        while (temp->siblling != nullptr)
          temp = temp->siblling;
        temp->siblling = newNode;
      }
      cout << "Child " << childData << " added to parent " << parentData << endl;
    } else {
      cout << "Parent node with data " << parentData << " not found." << endl;
    }
  }

  void insert(int val) {
    int parentData, childData;
    cout << "Enter the parent node: ";
    cin >> parentData;
    cout << "Enter the value of child node: ";
    cin >> childData;

    if (!root)
      create(val);

    insert_child(parentData, childData);
  }

  Node *search(Node *root, int val) {
    if (!root) return nullptr;
    if (root->data == val) return root;

    Node *found = search(root->child, val);
    if (found) return found;

    return search(root->siblling, val);
  }

  void display() {
    if (!root) return;
    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
      Node *curr = q.front();
      q.pop();
      cout << curr->data << " ";
      Node *child = curr->child;
      while (child) {
        q.push(child);
        child = child->siblling;
      }
    }
    cout << endl;
  }

  ~Tree() {
    delete root;
  }
};

int main() {
  return 0;
}