#ifndef DSA_H
#define DSA_H

#include <cstring>    
#include <iostream>

class SimpleVector {
private:
    int* arr;
    int capacity_val;
    int length;

    void resize(int new_capacity);

public:
    SimpleVector();
    ~SimpleVector();

    int size() const;
    int capacity() const;
    bool is_empty() const;

    void push(int item);
    void insert(int index, int item);
    void prepend(int item);

    int pop();
    void deleteAt(int index);
    void remove(int item);

    int at(int index) const;
    int find(int item) const;
};


#endif