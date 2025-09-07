#include "dsa.h"
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    SimpleVector v;
    v.push(5);
    v.push(6);
    v.push(7);
    cout << v.at(0) << " " << v.at(1) << " " << v.at(2) << " " << v.at(3);

    return 0;
}
