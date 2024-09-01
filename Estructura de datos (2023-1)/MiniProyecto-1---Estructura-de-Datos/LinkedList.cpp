#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

int LinkedList::size() {
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

void LinkedList::insert_left(int v) {
    Node* newNode = new Node(v);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insert_right(int v) {
    Node* newNode = new Node(v);
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::insert(int v, int i) {
    if (i == 0) {
        insert_left(v);
    } else {
        Node* newNode = new Node(v);
        Node* current = head;
        int j = 0;
        while (current && j < i-1) {
            current = current->next;
            j++;
        }
        if (current) {
            newNode->next = current->next;
            current->next = newNode;
        } else {
            std::cerr << "Error: index out of range" << std::endl;
            delete newNode;
        }
    }
}

void LinkedList::print() {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

bool LinkedList::find(int v) {
    Node* current = head;
    while (current) {
        if (current->data == v) {
            return true;
        }
        current = current->next;
    }
    return false;
}
