#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v = {4, 3, 7, 2};
  for (int i = 1; i <= v.size(); i++) {
    for (int j = 0; j <= v.size() - i; j++) {
      for (int k = j; k < j + i; k++) {
        cout << v[k] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}