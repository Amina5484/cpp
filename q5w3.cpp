//. Write a program to insert a new node at the end of a doubly Linked List.

#include <iostream>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data);

    if (head == nullptr) {
        // If the list is empty, set the new node as the head
        head = newNode;
    } else {
        Node* current = head;

        // Traverse the list to find the last node
        while (current->next != nullptr) {
            current = current->next;
        }

        // Update the pointers to insert the new node at the end
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to display the doubly linked list
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr; // Initialize an empty list

    // Insert some nodes at the end of the list
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);

    // Display the list
    std::cout << "Doubly Linked List: ";
    displayList(head);

    return 0;
}

