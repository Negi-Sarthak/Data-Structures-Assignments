#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c) {
    stack[++top] = c;
}
char pop() {
    return stack[top--];
}

int main() {
    char str[SIZE];
    cout << "Enter string: ";
    cin >> str;

    int n = strlen(str);

    for (int i = 0; i < n; i++)
        push(str[i]);

    cout << "Reversed string: ";
    for (int i = 0; i < n; i++)
        cout << pop();
    cout << endl;
    return 0;
}
