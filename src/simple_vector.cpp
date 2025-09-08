#include "dsa.h"
#include <iostream> 

SimpleVector::SimpleVector() {
    length = 0;
    capacity_val = 16;
    arr = new int[capacity_val];
}

SimpleVector::~SimpleVector() {
    delete[] arr;
}

void SimpleVector::resize(int new_capacity) {
    int* newArr = new int[new_capacity];
    memcpy(newArr, arr, length * sizeof(int));
    delete[] arr;
    arr = newArr;
    capacity_val = new_capacity;
}

int SimpleVector::size() const { return length; }
int SimpleVector::capacity() const { return capacity_val; }
bool SimpleVector::is_empty() const { return length == 0; }

void SimpleVector::push(int item) {
    if (length == capacity_val) resize(capacity_val * 2);
    *(arr + length) = item;
    length++;
}

void SimpleVector::insert(int index, int item) {
    if (index < 0 || index > length)
        throw std::out_of_range("Index out of bounds");

    if (length == capacity_val) resize(capacity_val * 2);

    for (int i = length; i > index; i--) {
        *(arr + i) = *(arr + i - 1);
    }

    *(arr + index) = item;
    length++;
}

void SimpleVector::prepend(int item) {
    insert(0, item);
}

int SimpleVector::pop() {
    if (length == 0) throw std::out_of_range("Array is empty");

    int item = *(arr + length - 1);
    length--;

    // shrink if size is 1/4 of capacity
    if (length > 0 && length == capacity_val / 4) {
        resize(capacity_val / 2);
    }

    return item;
}

void SimpleVector::deleteAt(int index) {
    if (index < 0 || index >= length)
        throw std::out_of_range("Index out of bounds");

    for (int i = index; i < length - 1; i++) {
        *(arr + i) = *(arr + i + 1);
    }
    length--;
}

// remove all occurrences of item
void SimpleVector::remove(int item) {
    int write = 0;
    for (int read = 0; read < length; read++) {
        if (*(arr + read) != item) {
            *(arr + write) = *(arr + read);
            write++;
        }
    }
    length = write;
}

int SimpleVector::at(int index) const {
    if (index < 0 || index >= length)
        throw std::out_of_range("Index out of bounds");
    return *(arr + index);
}

int SimpleVector::find(int item) const {
    for (int i = 0; i < length; i++) {
        if (*(arr + i) == item) return i;
    }
    return -1;
}
