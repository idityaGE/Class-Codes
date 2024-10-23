#include <iostream>
#include <queue>
using namespace std;

class Node {
 public:
  int data;
  Node* child;
  Node* sibling;
  Node(int d)
      : data(d), child(nullptr), sibling(nullptr) {}
};

class Tree {
  Node* root;

 public:
  Tree()
      : root(nullptr) {}

  void create(int d) {
    if (root == nullptr) root = new Node(d);
  }

  void insert_child(int parentData, int childData) {
    Node* parentNode = search(root, parentData);
    if (parentNode) {
      // Check for duplicate child
      Node* temp = parentNode->child;
      while (temp) {
        if (temp->data == childData) {
          cout << "Child " << childData << " already exists under parent " << parentData << endl;
          return;
        }
        temp = temp->sibling;
      }

      Node* newNode = new Node(childData);
      if (!parentNode->child) {
        parentNode->child = newNode;
      } else {
        temp = parentNode->child;
        while (temp->sibling) {
          temp = temp->sibling;
        }
        temp->sibling = newNode;
      }
      cout << "Child " << childData << " added to parent " << parentData << endl;
    } else {
      cout << "Parent node with data " << parentData << " not found." << endl;
    }
  }

  Node* search(Node* node, int data) {
    if (node == nullptr) return nullptr;
    if (node->data == data) return node;
    Node* found = search(node->child, data);
    if (found) return found;
    return search(node->sibling, data);
  }

  void display() {
    if (root == nullptr) return;
    queue<Node*> qq;
    qq.push(root);
    while (!qq.empty()) {
      Node* current = qq.front();
      qq.pop();
      cout << current->data << " ";
      Node* child = current->child;
      while (child) {
        qq.push(child);
        child = child->sibling;
      }
    }
    cout << endl;
  }

  void insert() {
    int parentData, childData;
    cout << "Enter the parent node: ";
    cin >> parentData;
    cout << "Enter the value of child node: ";
    cin >> childData;
    if (root == nullptr) {
      create(parentData);
      insert_child(parentData, childData);
    } else {
      insert_child(parentData, childData);
    }
  }
};

int main() {
  Tree t;
  t.create(1);
  t.insert_child(1, 3);
  t.insert_child(1, 3);  // This will now show a message about the duplicate
  t.insert_child(2, 4);  // Parent 2 doesn't exist, this will give a warning
  t.insert_child(2, 5);  // Same as above

  t.display();

  t.insert();
  t.insert();
  t.insert();
  t.insert();
  t.display();
  return 0;
}
