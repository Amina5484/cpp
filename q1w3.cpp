/*Write a C++ program to create and display a doubly Linked List. The structure must have no
less than three variables*/
#include <iostream>

// Define the Node structure for the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a new node at the end of the doubly linked list
void insertEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (!head) {
        // If the list is empty, the new node becomes the head
        head = newNode;
    } else {
        // Traverse to the end of the list
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        // Insert the new node at the end
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to display the doubly linked list
void displayList(Node* head) {
    std::cout << "Doubly Linked List: ";
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Initialize an empty doubly linked list
    Node* head = nullptr;

    // Insert nodes at the end of the list
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);

    // Display the doubly linked list
    displayList(head);

    // Clean up the allocated memory (not shown in this simple example for brevity)
    
    return 0;
}