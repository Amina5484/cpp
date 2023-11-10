//Write a program to display the details of the Nth node in a given doubly Linked List.
#include <iostream>

// Define a structure for a doubly linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Function to display the Nth node details
void displayNthNodeDetails(Node* head, int N) {
    if (head == nullptr) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    int count = 1;
    Node* current = head;

    // Traverse the list to find the Nth node
    while (current != nullptr && count < N) {
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        std::cout << "The list does not have " << N << " nodes." << std::endl;
    } else {
        std::cout << "Details of the " << N << "th node: " << std::endl;
        std::cout << "Data: " << current->data << std::endl;
        if (current->prev != nullptr)
            std::cout << "Previous Node Data: " << current->prev->data << std::endl;
        if (current->next != nullptr)
            std::cout << "Next Node Data: " << current->next->data << std::endl;
    }
}

int main() {
    // Create a sample doubly linked list
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    int N;
    std::cout << "Enter the value of N: ";
    std::cin >> N;

    displayNthNodeDetails(head, N);

    // Free memory by deleting nodes (not shown in detail here for brevity)
    
    return 0;
}