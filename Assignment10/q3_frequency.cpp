#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  vector<int> nums = {2, 3, 2, 4, 3, 2};
  unordered_map<int, int> freqMap;

  for (int n : nums) {
    freqMap[n]++;
  }

  for (auto pair : freqMap) {
    cout << pair.first << " -> " << pair.second << " times" << endl;
  }

  return 0;
}
