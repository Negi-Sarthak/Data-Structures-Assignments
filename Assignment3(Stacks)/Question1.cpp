#include <iostream>
using namespace std;

#define SIZE 10
int stack[SIZE];
int top = -1;

void push(int x) {
    if (top == SIZE - 1) {
        cout << "Stack Overflow\n";
    } else {
        stack[++top] = x;
        cout << x << " pushed\n";
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
    } else {
        cout << stack[top--] << " popped\n";
    }
}

void isEmpty() {
    if (top == -1) cout << "Stack is Empty\n";
    else cout << "Stack is not Empty\n";
}

void isFull() {
    if (top == SIZE - 1) cout << "Stack is Full\n";
    else cout << "Stack is not Full\n";
}

void display() {
    if (top == -1) cout << "Stack is Empty\n";
    else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
}

void peek() {
    if (top == -1) cout << "Stack is Empty\n";
    else cout << "Top element: " << stack[top] << endl;
}

int main() {
    int choice, val;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: cout << "Enter value: "; cin >> val; push(val); break;
        case 2: pop(); break;
        case 3: isEmpty(); break;
        case 4: isFull(); break;
        case 5: display(); break;
        case 6: peek(); break;
        case 7: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice\n";
        }
    } while (choice != 7);
    return 0;
}

