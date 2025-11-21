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

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
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

    void insertAfter(int existingVal, int newVal) {
        Node* temp = head;
        while (temp != nullptr && temp->data != existingVal) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            std::cout << "Node with value " << existingVal << " not found." << std::endl;
            return;
        }
        Node* newNode = new Node(newVal);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertBefore(int existingVal, int newVal) {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        if (head->data == existingVal) {
            insertAtBeginning(newVal);
            return;
        }
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr && curr->data != existingVal) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {
            std::cout << "Node with value " << existingVal << " not found." << std::endl;
            return;
        }
        Node* newNode = new Node(newVal);
        newNode->next = curr;
        prev->next = newNode;
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteNode(int val) {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        if (head->data == val) {
            deleteFromBeginning();
            return;
        }
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {
            std::cout << "Node with value " << val << " not found." << std::endl;
            return;
        }
        prev->next = curr->next;
        delete curr;
    }

    int searchNode(int val) {
        Node* temp = head;
        int position = 0;
        while (temp != nullptr) {
            if (temp->data == val) {
                return position;
            }
            temp = temp->next;
            position++;
        }
        return -1;
    }

    void display() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, existingVal;
    
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Insert at the beginning\n";
        std::cout << "2. Insert at the end\n";
        std::cout << "3. Insert before a node\n";
        std::cout << "4. Insert after a node\n";
        std::cout << "5. Delete from the beginning\n";
        std::cout << "6. Delete from the end\n";
        std::cout << "7. Delete a specific node\n";
        std::cout << "8. Search for a node\n";
        std::cout << "9. Display all nodes\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                std::cout << "Enter value to insert: ";
                std::cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                std::cout << "Enter existing node value: ";
                std::cin >> existingVal;
                std::cout << "Enter new node value: ";
                std::cin >> val;
                list.insertBefore(existingVal, val);
                break;
            case 4:
                std::cout << "Enter existing node value: ";
                std::cin >> existingVal;
                std::cout << "Enter new node value: ";
                std::cin >> val;
                list.insertAfter(existingVal, val);
                break;
            case 5:
                list.deleteFromBeginning();
                break;
            case 6:
                list.deleteFromEnd();
                break;
            case 7:
                std::cout << "Enter value of node to delete: ";
                std::cin >> val;
                list.deleteNode(val);
                break;
            case 8:
                std::cout << "Enter value to search: ";
                std::cin >> val;
                {
                    int pos = list.searchNode(val);
                    if (pos != -1) {
                        std::cout << "Node found at position: " << pos << std::endl;
                    } else {
                        std::cout << "Node not found." << std::endl;
                    }
                }
                break;
            case 9:
                list.display();
                break;
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
