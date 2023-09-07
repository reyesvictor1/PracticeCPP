#include <iostream>

struct Node {
    int data;   // value stored in the node
    Node* next; // pointer to the next node
};

void insertEnd(Node*& head, int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (!head) {
        // if the list is empty, set the new node as the head of the list
        head = newNode; // the head pointer now points to the memory address of newNode
    } else {
        // otherwise, append the new node to the end of the list
        Node *currentNode = head;
        while (currentNode->next) { // keep looking until the next Node pointer is nullptr (the end of the list)
            currentNode = currentNode->next;
        }
        currentNode->next = newNode; // once the end of the list is found, append the new node to it
    }
}

void displayList(const Node* head) {
    const Node* currentNode = head; // currentNode takes the memory address of the head (first element in the list)
    while (currentNode) { // while not reaching the end of the list (nullptr)
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next; // currentNode now takes the memory address of the next node
    }
    std::cout << std::endl;
}

int main() {

    // initialize an empty linked list
    Node *head = nullptr; 

    // insert elements at the end of the linked list
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);

    // display the linked list
    std::cout << "Linked List: ";
    displayList(head); // argument is the memory address of the first element in the list

    return 0;
}