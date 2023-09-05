// zavd_76.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    Node* temp;
    temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void CountMinus(Node* head) {
    int count = 0;
    Node* temp = nullptr;
    temp = head;

    while (temp != nullptr) {
        if (temp->value < 0) {
            count++;
            temp = temp->next;
        }
        else {
            temp = temp->next;
        }
    }

    cout << "Count numbers with minus: " << count << endl;
}

void EnlargeElement(Node*& head, int value) {
    Node* temp = head;
    while (temp != nullptr) {
        temp->value += value;
        temp = temp->next;
    }
}



bool removeNumber(Node*& head, int num) {
    if (head->value == num) {
        if (head->next == nullptr) // якщо нода єдина в списку  
        {
            head = nullptr;
            return false;
        }
        head = head->next;
        return true;
    }
    Node* tmp = head;
    while (tmp->next != nullptr) {
        if (tmp->next->value == num) {
            if (tmp->next->next == nullptr) {
                tmp->next = nullptr;
                return false;
            }
            tmp->next = tmp->next->next;
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}
void removeNumbers(Node*& head, int num) {
    while (removeNumber(head, num)) {
        cout << num << " was deleted " << endl;
    }
}



void InsertAfterValue(Node*& head, int V1, int V2) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->value == V1) {
            Node* newNode = new Node(V2);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
        else {
            temp = temp->next;
        }
    }
}

int main()
{
    Node* head = nullptr;
    int size;
    cout << "Enter size: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        int number;
        cout << "Enter number: ";
        cin >> number;
        putNodeToTail(head, number);
    }
    display(head);
    int choice;
    cout << "Make your choice" << endl;
    cout << "1 - Count minus\n2 - Enlarge element\n3 - Delete element\n4 - Insert after value" << endl;
    cin >> choice;
    if (choice == 1) {
        CountMinus(head);
    }
    else if (choice == 2) {
        int value;
        cout << "Enter value to enlarge elements by: ";
        cin >> value;
        EnlargeElement(head, value);
        display(head);
    }
    else if (choice == 3) {
        int num;
        cout << "Enter number to delete: ";
        cin >> num;
        removeNumbers(head, num);
        display(head);
    }
    else if (choice == 4) {
        int V1, V2;
        cout << "Enter value to search for (V1): ";
        cin >> V1;
        cout << "Enter value to insert (V2): ";
        cin >> V2;
        InsertAfterValue(head, V1, V2);
        display(head);
    }
    else {
        cout << "Wrong number" << endl;
    }
}
