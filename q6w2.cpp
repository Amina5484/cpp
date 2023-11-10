//Write a program to display the details of the Nth node in a given Singly Linked List
#include <iostream>

struct Node {
    int data;
    Node* next;
};

void displayNthNode(Node* head, int n) {
    Node* current = head;
    int count = 1;

    while (current != nullptr) {
        if (count == n) {
            std::cout << "Data of the " << n << "th node: " << current->data << std::endl;
            return;
        }
        current = current->next;
        count++;
    }

    std::cout << "Invalid position. The linked list does not have " << n << " nodes." << std::endl;
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

    // Display the details of the Nth node
    int n = 2; // Example: Display details of the 2nd node
    displayNthNode(head, n);

    // Clean up memory
    delete head;
    delete second;
    delete third;

    return 0;
}