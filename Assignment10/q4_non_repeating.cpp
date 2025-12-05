#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  vector<int> input = {4, 5, 1, 2, 0, 4};
  unordered_map<int, int> m;

  for (int i = 0; i < input.size(); i++)
    m[input[i]]++;

  for (int i = 0; i < input.size(); i++) {
    if (m[input[i]] == 1) {
      cout << input[i];
      break;
    }
  }
  return 0;
}
