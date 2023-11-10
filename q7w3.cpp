//Write a program to insert a new node at any position of a doubly Linked List.
#include <iostream>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to insert a new node at any position in the doubly linked list
void insertAtPosition(Node*& head, int position, int newData) {
    // Create a new node
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    // If the list is empty or position is 1, insert at the beginning
    if (head == nullptr || position == 1) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    // Traverse the list to find the position
    Node* current = head;
    for (int i = 1; i < position - 1 && current != nullptr; ++i) {
        current = current->next;
    }

    // If the given position is greater than the length of the list,
    // insert at the end
    if (current == nullptr) {
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
        return;
    }

    // Insert the new node at the specified position
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

// Function to display the doubly linked list
void displayList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    Node* head = nullptr;

    // Insert elements at the beginning
    insertAtPosition(head, 1, 10);
    insertAtPosition(head, 1, 20);
    insertAtPosition(head, 1, 30);

    std::cout << "Doubly Linked List: ";
    displayList(head);

    // Insert at a specific position
    insertAtPosition(head, 2, 15);

    std::cout << "Doubly Linked List after insertion: ";
    displayList(head);

    return 0;
}