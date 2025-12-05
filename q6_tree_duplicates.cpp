#include <iostream>
#include <unordered_set>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasDuplicate(TreeNode *root, unordered_set<int> &s) {
  if (root == NULL)
    return false;

  if (s.count(root->val))
    return true;
  s.insert(root->val);

  return hasDuplicate(root->left, s) || hasDuplicate(root->right, s);
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(2);

  unordered_set<int> s;
  if (hasDuplicate(root, s))
    cout << "Duplicates Found";
  else
    cout << "No Duplicates";

  return 0;
}
