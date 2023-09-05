// zavd_76_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"
using namespace std;

void putNodeToTail(Node*& head, int value) {
    Node* n = new Node(value);
    if (head == nullptr) {
        head = n;
        return;
    }
    Node* tmp = nullptr;
    tmp = head;

    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = n;
}

void display(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void reverseLinkedList(Node*& head) {
    Node* temp = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = temp;
        temp = current;
        current = next;
    }
    head = temp;
}

int main()
{
    int size;
    cout << "Enter the size of the linked list: ";
    cin >> size;

    Node* head = nullptr;
    for (int i = 0; i < size; i++) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        putNodeToTail(head, value);
    }

    cout << "Linked list: ";
    display(head);

    reverseLinkedList(head);

    cout << "Reversed linked list: ";
    display(head);
}

