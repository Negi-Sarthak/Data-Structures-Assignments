#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  vector<int> A = {1, 2, 3, 4};
  vector<int> B = {3, 4, 5, 6};

  unordered_set<int> s;
  for (int x : A)
    s.insert(x);

  for (int i = 0; i < B.size(); i++) {
    if (s.find(B[i]) != s.end()) {
      cout << B[i];
      if (i != B.size() - 1)
        cout << ", ";
    }
  }
  return 0;
}
