#include "Array.h"
#include <iostream>

Array::Array(int b) {
    this->b = b;
    this->length = 0;
    this->arr = new int[b];
}

Array::~Array() {
    delete[] arr;
}

int Array::size() {
    return length;
}

void Array::insert_left(int v) {
    if (length >= b) {
        std::cout << "Error: el arreglo está lleno" << std::endl;
        return;
    }
    for (int i = length; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = v;
    length++;
}

void Array::insert_right(int v) {
    if (length >= b) {
        std::cout << "Error: el arreglo está lleno" << std::endl;
        return;
    }
    arr[length] = v;
    length++;
}

void Array::insert(int v, int i) {
    if (i < 0 || i > length || length >= b) {
        std::cout << "Error: índice inválido o el arreglo está lleno" << std::endl;
        return;
    }
    for (int j = length; j > i; j--) {
        arr[j] = arr[j-1];
    }
    arr[i] = v;
    length++;
}

void Array::print() {
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

bool Array::find(int v) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == v) {
            return true;
        }
    }
    return false;
}
