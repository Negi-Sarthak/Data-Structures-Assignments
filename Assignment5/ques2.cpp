#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data;
            if (temp->next != nullptr) {
                std::cout << " -> ";
            }
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void countAndDelete(int key) {
        if (head == nullptr) {
            std::cout << "List is empty, count is 0." << std::endl;
            return;
        }

        int count = 0;
        Node* temp = head;
        
        while (temp != nullptr) {
            if (temp->data == key) {
                count++;
            }
            temp = temp->next;
        }

        Node* prev = nullptr;
        Node* current = head;
        
        while (current != nullptr) {
            if (current->data == key) {
                if (prev == nullptr) {
                    head = current->next;
                    delete current;
                    current = head;
                } else {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
            } else {
                prev = current;
                current = current->next;
            }
        }
        
        std::cout << "Count: " << count << std::endl;
        std::cout << "Updated Linked List: ";
        display();
    }
};

int main() {
    SinglyLinkedList list;
    
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtEnd(1);

    int key = 1;

    std::cout << "Original Linked List: ";
    list.display();

    list.countAndDelete(key);

    return 0;
}