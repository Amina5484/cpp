//
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

Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
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

    // Display the original linked list
    std::cout << "Original Linked List: ";
    displayLinkedList(head);

    // Reverse the linked list
    Node* reversedHead = reverseLinkedList(head);

    // Display the reversed linked list
    std::cout << "Reversed Linked List: ";
    displayLinkedList(reversedHead);

    // Clean up memory
    delete reversedHead;

    return 0;
}