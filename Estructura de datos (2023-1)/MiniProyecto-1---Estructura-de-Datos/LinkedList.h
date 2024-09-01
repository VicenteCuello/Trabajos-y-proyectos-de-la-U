#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ListArrADT.h"

class LinkedList : public ListArrADT {
private:
    struct Node {
        int data;
        Node* next;
        Node(int d) : data(d), next(nullptr) {}
    };
    Node* head;

public:
    LinkedList();
    ~LinkedList();
    int size();
    void insert_left(int v);
    void insert_right(int v);
    void insert(int v, int i);
    void print();
    bool find(int v);
};

#endif
