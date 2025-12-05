#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool hasDuplicate(vector<int>& arr) {
    unordered_set<int> seen;
    for(int i=0;i<arr.size();i++){
       if(seen.count(arr[i])) return true;
       seen.insert(arr[i]);
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    if(hasDuplicate(nums)) cout << "true";
    else cout << "false";
    
    return 0;
}
