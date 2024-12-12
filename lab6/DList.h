#pragma once
#ifndef DLIST_H
#define DLIST_H

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;

    DNode(int value);
};

class DList {
private:
    DNode* head;

public:
    DList();
    void add(int value);
    void remove(int value);
    bool isSymmetric(int i, int j);
};

#endif // DLIST_H
