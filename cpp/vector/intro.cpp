#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  // Vector Basics
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);

  // Accessing elements
  cout << "Accessing elements:" << endl;
  cout << "v[0]: " << v[0] << endl;  // 1
  cout << "v[1]: " << v[1] << endl;  // 2

  // Size of vector - number of elements in vector
  cout << "Size of vector: " << v.size() << endl;  // 5
  // Capacity of vector - how many elements can be stored without resizing
  cout << "Capacity of vector: " << v.capacity() << endl;  // 8

  // Iterating over vector
  cout << "Iterating over vector:" << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;

  // Removing elements
  cout << "Removing elements:" << endl;
  v.pop_back();              // Removes the last element   // time complexity O(1)
  cout << "Size of vector after pop_back(): " << v.size() << endl;  // 4

  v.clear();                 // Removes all elements  // time complexity O(n)
  cout << "Size of vector after clear(): " << v.size() << endl;  // 0

  // Accessing first and last elements
  cout << "Accessing first and last elements:" << endl;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  cout << "First element: " << v.front() << endl;  // 1
  cout << "Last element: " << v.back() << endl;   // 3

  // Accessing element at a given index
  cout << "Accessing element at a given index:" << endl;
  cout << "v.at(1): " << v.at(1) << endl;  // 2

  // Checking if vector is empty
  cout << "Checking if vector is empty:" << endl;
  cout << "Is vector empty? " << (v.empty() ? "Yes" : "No") << endl;  // 0

  // Resizing vector
  cout << "Resizing vector:" << endl;
  v.resize(10);                  // Size of vector becomes 10
  cout << "Size of vector after resize(): " << v.size() << endl;      // 10  // initialize remaining elements with 0
  cout << "Capacity of vector after resize(): " << v.capacity() << endl;  // 10

  // Reserving space for elements
  cout << "Reserving space for elements:" << endl;
  v.reserve(20);
  cout << "Size of vector after reserve(): " << v.size() << endl;      // 10
  cout << "Capacity of vector after reserve(): " << v.capacity() << endl;  // 20

  // Inserting elements
  cout << "Inserting elements:" << endl;
  v.insert(v.begin() + 2, 7);  // Insert 7 at index 2
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;

  // Erasing elements
  cout << "Erasing elements:" << endl;
  v.erase(v.begin() + 2);  // Erase element at index 2
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;

  v.erase(v.begin() + 2, v.begin() + 4);  // Erase elements from index 2 to 4
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;

  // Iterating using iterators
  cout << "Iterating using iterators:" << endl;
  vector<int>::iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  // Iterating in reverse
  cout << "Iterating in reverse:" << endl;
  vector<int>::reverse_iterator rit;
  for (rit = v.rbegin(); rit != v.rend(); rit++) {
    cout << *rit << " ";
  }
  cout << endl;

  // Iterating using auto
  cout << "Iterating using auto:" << endl;
  for (auto i = v.begin(); i != v.end(); i++) {
    cout << *i << " ";
  }
  cout << endl;

  // Assigning values
  cout << "Assigning values:" << endl;
  vector<int> v1(5, 10);  // Vector of size 5 with all elements as 10
  for (int i = 0; i < v1.size(); i++) {
    cout << v1[i] << " ";
  }
  cout << endl;

  // Swapping vectors
  cout << "Swapping vectors:" << endl;
  vector<int> v2(5, 20);
  v1.swap(v2); // Swaps the elements of v1 and v2
  for (int i = 0; i < v1.size(); i++) {
    cout << v1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < v2.size(); i++) {
    cout << v2[i] << " ";
  }
  cout << endl;

  // Sorting vector
  cout << "Sorting vector:" << endl;
  vector<int> v3 = {5, 2, 9, 1, 5};
  sort(v3.begin(), v3.end());
  for (int i = 0; i < v3.size(); i++) {
    cout << v3[i] << " ";
  }
  cout << endl;

  // Sorting in descending order
  cout << "Sorting in descending order:" << endl;
  sort(v3.rbegin(), v3.rend());
  for (int i = 0; i < v3.size(); i++) {
    cout << v3[i] << " ";
  }
  cout << endl;

  // Sorting using custom comparator
  cout << "Sorting using custom comparator:" << endl;
  sort(v3.begin(), v3.end(), greater<int>());
  for (int i = 0; i < v3.size(); i++) {
    cout << v3[i] << " ";
  }
  cout << endl;

  // Finding elements
  cout << "Finding elements:" << endl;
  vector<int> v4 = {1, 2, 3, 4, 5};
  auto it1 = find(v4.begin(), v4.end(), 3); // Returns an iterator to the element 3
  if (it1 != v4.end()) {
    cout << "Element found" << endl;
  } else {
    cout << "Element not found" << endl;
  }

  auto it2 = find(v4.begin(), v4.end(), 10); // Returns an iterator to the end of the vector
  if (it2 != v4.end()) {
    cout << "Element found" << endl;
  } else {
    cout << "Element not found" << endl;
  }

  // Binary search
  cout << "Binary search:" << endl;
  vector<int> v5 = {1, 2, 3, 4, 5};
  bool present = binary_search(v5.begin(), v5.end(), 3);  // Returns true
  cout << "Is 3 present? " << (present ? "Yes" : "No") << endl;

  present = binary_search(v5.begin(), v5.end(), 10);  // Returns false
  cout << "Is 10 present? " << (present ? "Yes" : "No") << endl;

  // Finding maximum and minimum elements
  cout << "Finding maximum and minimum elements:" << endl;
  vector<int> v6 = {1, 2, 3, 4, 5};
  auto max = max_element(v6.begin(), v6.end());  // Returns an iterator to the maximum element
  cout << "Maximum element: " << *max << endl;

  vector<int> v7 = {1, 2, 3, 4, 5};
  auto min = min_element(v7.begin(), v7.end());  // Returns an iterator to the minimum element
  cout << "Minimum element: " << *min << endl;

  // Counting occurrences
  cout << "Counting occurrences:" << endl;
  vector<int> v8 = {1, 2, 3, 4, 5, 3, 3};
  int count = std::count(v8.begin(), v8.end(), 3);  // Returns the count of 3
  cout << "Count of 3: " << count << endl;

  // Removing elements
  cout << "Removing elements:" << endl;
  vector<int> v9 = {1, 2, 3, 4, 5, 3, 3};
  auto it3 = remove(v9.begin(), v9.end(), 3);  // Removes all occurrences of 3
  for (auto i = v9.begin(); i != it3; i++) {
    cout << *i << " ";
  }
  cout << endl;

  // Removing elements using predicate
  cout << "Removing elements using predicate:" << endl;
  vector<int> v10 = {1, 2, 3, 4, 5, 3, 3};
  auto it4 = remove_if(v10.begin(), v10.end(), [](int x) { return x > 3; });  // Removes all elements greater than 3
  for (auto i = v10.begin(); i != it4; i++) {
    cout << *i << " ";
  }
  cout << endl;

  // Calculating distance
  cout << "Calculating distance:" << endl;
  vector<int> v11 = {1, 2, 3, 4, 5};
  auto it5 = find(v11.begin(), v11.end(), 3);
  cout << "Distance from beginning to 3: " << distance(v11.begin(), it5) << endl;

  return 0;
}