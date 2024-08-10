#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v = {9, 5, 8, 12, 2, 3, 7, 4};
  int suffix = INT_MIN;
  int ans = INT_MIN;
  for (int i = v.size() - 2; i >= 0; i--) {
    suffix = max(suffix, v[i + 1]);
    ans = max(ans, suffix - v[i]);
  }
  cout << ans << endl;

  return 0;
}