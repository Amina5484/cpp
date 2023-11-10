/*Write a C++ program to create and display a Singly Linked List. The structure must have no
less than three variable*/
#include <iostream>

struct Node {
    int data;
    Node* next;
};

void displayLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create the nodes
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // Assign data to the nodes
    head->data = 1;
    second->data = 2;
    third->data = 3;

    // Connect the nodes
    head->next = second;
    second->next = third;
    third->next = nullptr;

    // Display the linked list
    displayLinkedList(head);

    // Clean up memory
    delete head;
    delete second;
    delete third;

    return 0;
}