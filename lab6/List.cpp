#include "List.h"
#include <iostream>

Node::Node(int value) : data(value), next(nullptr) {}

List::List() : head(nullptr) {}

void List::add(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void List::remove(int value) {
    if (!head) return;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next && current->next->data != value) {
        current = current->next;
    }

    if (current->next) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

void List::print() {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

List List::createListFromDifference(List& L1, List& L2) {
    List L;
    Node* current1 = L1.head;
    while (current1) {
        Node* current2 = L2.head;
        bool found = false;
        while (current2) {
            if (current1->data == current2->data) {
                found = true;
                break;
            }
            current2 = current2->next;
        }
        if (!found) {
            L.add(current1->data);
        }
        current1 = current1->next;
    }
    return L;
}
