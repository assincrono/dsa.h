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

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int item);
};

class LinkedList {
private:
    int length;
    Node* head;
    Node* tail;

public:
    LinkedList();
    
    void push_front(int val);
    void push_back(int val);
    void insert(int index, int val);
    void erase(int index);
    int pop_front();
    int pop_back();
    void remove_value(int value);

    int front();
    int back();
    int value_n_from_end(int n);
    int value_at(int index);
    int size();
    bool empty();

    void reverse();
};


#endif