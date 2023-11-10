#include <iostream>

// Node structure for a doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
    
    // Constructor
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Function to count nodes in a doubly linked list
int countNodes(Node* head) {
    int count = 0;
    
    // Traverse the list and count nodes
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    
    return count;
}

// Function to display the elements of a doubly linked list
void displayList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    // Display the doubly linked list
    std::cout << "Doubly Linked List: ";
    displayList(head);

    // Count the number of nodes
    int nodeCount = countNodes(head);
    std::cout << "Number of nodes: " << nodeCount << std::endl;

    // Clean up memory (free the allocated nodes)
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}