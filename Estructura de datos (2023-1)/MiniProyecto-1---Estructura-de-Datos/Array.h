#ifndef ARRAY_H
#define ARRAY_H

#include "ListArrADT.h"

class Array : public ListArrADT {
private:
    int* arr; 
    int b; 
    int length; 

public:
    Array(int b); 
    ~Array(); 

    
    int size() override;
    void insert_left(int v) override;
    void insert_right(int v) override;
    void insert(int v, int i) override;
    void print() override;
    bool find(int v) override;
};    

#endif
