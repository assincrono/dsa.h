#include "dsa.h"
#include <iostream>
using namespace std;

int main() {
    SimpleVector v;
    v.push(9);
    v.push(5);
    v.push(6);
    v.push(7);
    v.deleteAt(0);

    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }

    return 0;
}
