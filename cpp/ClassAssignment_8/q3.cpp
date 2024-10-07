/*
Assume, an application needs to store the name and branch information of some
random students. This application required functionality that we can search the
student’s information by providing the roll number of the student. Therefore, design a
hash table ADT for the same, where the roll number may be selected as key of the
information. Implement the same in C++.
*/

#include <iostream>
#include <string>
using namespace std;

class Student {
 public:
  int rollNumber;
  string name;
  string branch;

  Student(int roll, string studentName, string studentBranch) {
    rollNumber = roll;
    name = studentName;
    branch = studentBranch;
  }
};

class Node {
 public:
  Student *student;
  Node *next;

  Node(Student *student) {
    this->student = student;
    next = nullptr;
  }
};

class LinkedList {
  Node *head;

 public:
  LinkedList() {
    head = nullptr;
  }
  
  void insert(Student *student) {
    Node *newNode = new Node(student);
    newNode->next = head;
    head = newNode;
  }

  Student *search(int rollNumber) {
    Node *temp = head;
    while (temp != nullptr) {
      if (temp->student->rollNumber == rollNumber)
        return temp->student;
      temp = temp->next;
    }
    return nullptr;
  }
};

class HashTable {
  LinkedList *Heads;
  int size;

 public:
  HashTable(int size) {
    this->size = size;
    Heads = new LinkedList[size];
  }

  void insert(Student *student) {
    int key = student->rollNumber % size;
    Heads[key].insert(student);
  }

  Student *search(int rollNumber) {
    int key = rollNumber % size;
    return Heads[key].search(rollNumber);
  }
};

int main() {
  HashTable ht(10);

  Student *s1 = new Student(1, "John Doe", "CSE");
  Student *s2 = new Student(2, "Jane Doe", "ECE");
  Student *s3 = new Student(3, "Alice", "EEE");

  ht.insert(s1);
  ht.insert(s2);
  ht.insert(s3);

  Student *s = ht.search(2);
  if (s != nullptr)
    cout << "Student found: " << s->name << " " << s->branch << endl;
  else
    cout << "Student not found" << endl;
  
  Student *s4 = new Student(4, "Bob", "ME");
  ht.insert(s4);

  s = ht.search(4);
  if (s != nullptr)
    cout << "Student found: " << s->name << " " << s->branch << endl;
  else
    cout << "Student not found" << endl;
  
  return 0;
}

// Output
/*
Student found: Jane Doe ECE
Student found: Bob ME
*/

// Hierarchical Order
/*
  HashTable (array of head of LL) -> LinkedList (LL of Node) -> Node (each node contain student) -> Student (rollNumber, name, branch)
*/