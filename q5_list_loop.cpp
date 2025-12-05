#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
  int val;
  Node *next;
  Node(int v) : val(v), next(NULL) {}
};

bool hasLoop(Node *head) {
  unordered_set<Node *> s;
  while (head != NULL) {
    if (s.find(head) != s.end())
      return true;
    s.insert(head);
    head = head->next;
  }
  return false;
}

int main() {
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);

  head->next->next->next->next = head->next;

  if (hasLoop(head))
    cout << "true";
  else
    cout << "false";

  return 0;
}
