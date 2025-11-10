#include <iostream>
#include <cmath>
#include <iomanip>

class Circle {
// complete declaration for Circle class here
private:

protected:
    double m_radius;
    double m_area;
    void calcArea(double radius) {
            m_area = M_PI * pow(m_radius,2.0);
    }
public:
    Circle() {
        m_radius = 1.0;
        m_area = 3.14;
    }
    Circle(double radius) {
        if (radius > 0) {
            m_radius = radius;
            calcArea(m_radius);
        }
        else {
            m_radius = 1;
            m_area = 3.14;
        }
    }
    virtual void display() {
        std::cout.setf(std::ios::fixed);
        std::cout.precision(2);
        std::cout << "\nThe area of a circle with ...\na radius of " << m_radius << " inches\n";
        std::cout <<"has an area of " << m_area << " square inches.\n";
    }
};

class Cylinder : public Circle {
// complete declaration for Cylinder class here
private:
    double m_height;
    double m_volume;
    void calcVolume(double r, double h) {
        if (r>0 and h>0) {
           m_volume = m_area * m_height;
        }
    }
public:
    Cylinder() {
        m_height = 1.0;
        m_volume = 1.0;
    }
    Cylinder(double radius, double height) : Circle(radius) {
        if (height>0) {
            m_height = height;
            calcVolume(radius,height);
        }
        else {
            m_height = 1;
            m_volume = 3.14;
        }
    }
    void display() override{
        Circle::display();
        std::cout << "And the volume of a Cylinder with...\na circular end area of " << m_area <<" square inches\n";
        std::cout << "and a height of " << m_height << " inches\n";
        std::cout << "has a volume of " << m_volume << " cubic inches.\n";
    }
    // override a + operator
    Cylinder operator+(Cylinder &Right) {
        Cylinder temp;
        // code to implement the addition of two cylinders
        temp.m_radius = this->m_radius + Right.m_radius;
        temp.calcArea(temp.m_radius);
        temp.m_volume = this->m_volume + Right.m_volume;
        temp.m_height = temp.m_volume / temp.m_area;
        return temp;
    }
};

int main() {
    double a(2.5), b(1.25);
    double c = a + b;
    std::cout << "Sum " << c << "\n";

    Cylinder cylA(  3.125, 10.5);
    cylA.display();
    Cylinder cylB( 4.5, 2.125);
    cylB.display();
    // cylC = cylA.+(cylB)
    Cylinder cylC = cylA + cylB;
    cylC.display();
    //std::cout << "Sum " << cylC << "\n";


    /*Circle c1, c2(5);
    c1.display();
    c2.display();
    Circle *cl1 = new Cylinder(3.5,8.65);
    cl1->display();
    delete cl1;*/

    return 0;
}
