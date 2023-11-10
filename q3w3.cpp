//count the number of nodes in a singly linked list
#include <iostream>

struct Node {
    int data;
    Node* next;
};

int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
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

    // Count the number of nodes
    int nodeCount = countNodes(head);
    std::cout << "Number of nodes: " << nodeCount << std::endl;

    // Clean up memory
    delete head;
    delete second;
    delete third;

    return 0;
}