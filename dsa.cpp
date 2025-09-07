#include "dsa.h"

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

class SimpleVector {
    private:
        int* arr = new int[2];
        int length;

        void resize() {
            int* newArr = new int[length * 2];
            memcpy(newArr, arr, length * sizeof(int));
            delete [] arr;
            arr = newArr;
        }

    public:
        SimpleVector() {
            length = 0;
        }

        int size() {
            return length;
        }

        int capacity() {
            return sizeof(arr) / sizeof(int);
        }

        void push(int e) {
            if (size() == capacity()) {
                resize();
            }

            arr[length] = e;
            length += 1;
        }

        int pop() {
            if (length == 0) {
                cout << "Array is empty";
                return -1;
            }

            length--;
            return arr[length + 1];
        }

        int at(int index) {
            if (index > length - 1) {
                cout << "Index out of bounds.\n";
                return -1;
            }

            return arr[index];
        }
};