#pragma once
#ifndef LIST_H
#define LIST_H

class Node {
public:
    int data;
    Node* next;

    Node(int value);
};

class List {
private:
    Node* head;

public:
    List();
    void add(int value);
    void remove(int value);
    void print();
    static List createListFromDifference(List& L1, List& L2);
};

#endif // LIST_H
