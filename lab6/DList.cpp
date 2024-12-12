#include "DList.h"
#include <iostream>

DNode::DNode(int value) : data(value), next(nullptr), prev(nullptr) {}

DList::DList() : head(nullptr) {}

void DList::add(int value) {
    DNode* newNode = new DNode(value);
    if (!head) {
        head = newNode;
    }
    else {
        DNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void DList::remove(int value) {
    if (!head) return;

    if (head->data == value) {
        DNode* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
        return;
    }

    DNode* current = head;
    while (current && current->data != value) {
        current = current->next;
    }

    if (current) {
        if (current->next) {
            current->next->prev = current->prev;
        }
        if (current->prev) {
            current->prev->next = current->next;
        }
        delete current;
    }
}

bool DList::isSymmetric(int i, int j) {
    DNode* left = head;
    DNode* right = head;

    // Перемещаем указатель right на j-й элемент
    for (int k = 0; k < j && right; ++k) {
        right = right->next;
    }

    // Перемещаем указатель left на i-й элемент
    for (int k = 0; k < i && left; ++k) {
        left = left->next;
    }

    // Проверяем симметричность
    while (left && right && left != right && left->prev != right) {
        if (left->data != right->data) {
            return false;
        }
        left = left->next;
        right = right->prev;
    }

    return true;
}
