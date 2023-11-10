//Write a program to insert a new node at any position of a Singly Linked List
#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize data and next pointer
    Node(int value) : data(value), next(nullptr) {}
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at a given position
    void insertAtPosition(int value, int position) {
        Node* newNode = new Node(value);

        // If the position is the head, update the head
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        // Traverse to the node before the desired position
        for (int i = 1; i < position - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }

        // If the position is invalid, do not insert
        if (temp == nullptr) {
            cout << "Invalid position\n";
            delete newNode;
            return;
        }

        // Insert the new node at the specified position
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;

    // Insert some nodes at the beginning
    myList.insertAtPosition(3, 1);
    myList.insertAtPosition(5, 1);
    myList.insertAtPosition(7, 1);

    // Display the original list
    cout << "Original List: ";
    myList.display();

    // Insert a new node at position 2
    myList.insertAtPosition(4, 2);

    // Display the updated list
    cout << "Updated List: ";
    myList.display();

    return 0;
}