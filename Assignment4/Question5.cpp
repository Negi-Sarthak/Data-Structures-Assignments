#include <iostream>
using namespace std;
#define SIZE 100

class Queue {
private:
    int qu[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int element) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow!" << endl;
        } else {
            if (front == -1) front = 0;
            rear++;
            qu[rear] = element;
        }
    }

    int dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int temp = qu[front];
        front++;
        return temp;
    }

    int peek() {
        if (front == -1 || front > rear) {
            cout << "Queue Empty!" << endl;
            return -1;
        }
        return qu[front];
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    int size() {
        if (isEmpty()) return 0;
        return (rear - front + 1);
    }
};

class Stack {
private:
    Queue q;

public:
    void push(int x) {
        q.enqueue(x);

        int s = q.size();
        for (int i = 0; i < s - 1; i++) {
            int val = q.dequeue();
            q.enqueue(val);
        }
    }

    int pop() {
        if (q.isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return q.dequeue();
    }

    int top() {
        return q.peek();
    }

    bool isEmpty() {
        return q.isEmpty();
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;  
    cout << "Pop: " << st.pop() << endl;  
    cout << "Top: " << st.top() << endl;  

    return 0;
}
