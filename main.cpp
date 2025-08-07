#include <iostream>
#include <cmath>

class Circle {
// complete declaration for Circle class here

};

class Cylinder : public Circle {
// complete declaration for Cylinder class here

};

int main() {
    Circle c1, c2(5.25);
    c1.display();
    c2.display();
    Cylinder cl1(3.5,8.65);
    cl1.display();
    return 0;
}
