#include <iostream>
#include <cmath>

class Circle {
// complete declaration for Circle class here
private:
    double m_radius;
protected:
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
};

int main() {
    Circle c1, c2(5);
    c1.display();
    c2.display();
    Circle *cl1 = new Cylinder(3.5,8.65);
    cl1->display();

    return 0;
}
