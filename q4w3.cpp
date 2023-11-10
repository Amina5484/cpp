// write a program to insert a new node at the beginning of a doubly Linked List
#include <iostream>

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
    
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Function to insert a new node at the beginning of a doubly linked list
void insertAtBeginning(Node*& head, int val) {
    // Create a new node
    Node* newNode = new Node(val);
    
    // Update next and prev pointers of the new node
    newNode->next = head;
    newNode->prev = nullptr;
    
    // Update the prev pointer of the existing head (if it exists)
    if (head != nullptr) {
        head->prev = newNode;
    }
    
    // Update the head to point to the new node
    head = newNode;
}

// Function to print the doubly linked list
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Driver program
int main() {
    // Create an empty doubly linked list
    Node* head = nullptr;

    // Insert elements at the beginning
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);

    // Print the doubly linked list
    std::cout << "Doubly Linked List: ";
    printList(head);

    return 0;
}