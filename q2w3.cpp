//
#include <iostream>

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
    
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Function to reverse a doubly linked list
void reverseDoublyLinkedList(Node*& head) {
    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        // Swap the prev and next pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node
        current = current->prev;
    }

    // Update the head to the last node
    if (temp != nullptr) {
        head = temp->prev;
    }
}

// Function to print a doubly linked list
void printDoublyLinkedList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating a sample doubly linked list: 1 <-> 2 <-> 3 <-> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    std::cout << "Original Doubly Linked List: ";
    printDoublyLinkedList(head);

    // Reverse the doubly linked list
    reverseDoublyLinkedList(head);

    std::cout << "Reversed Doubly Linked List: ";
    printDoublyLinkedList(head);

    // Clean up: free the memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}