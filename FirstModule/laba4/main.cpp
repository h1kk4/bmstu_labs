#include <iostream>
#include "TCircle.h"
#include "Ellipse.h"
int main() {
    TCircle obj1(2);
    Ellipse obj2(1,2);
    obj1.Print();
    obj2.Print();
    return 0;
}