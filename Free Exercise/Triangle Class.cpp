#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class Triangle{
public:
    Triangle(double x, double y, double z);
    void print();
    double perimeter() const;
    double area() const;
private:
    double x;
    double y;
    double z;
};


Triangle::Triangle(double _x, double _y, double _z)
{
    this->x = _x;
    this->y = _y;
    this->z = _z;
}

void Triangle::print()
{
    cout << x << endl << y << endl << z << endl;
}

double Triangle::perimeter() const
{
    return x + y + z;
}

double Triangle::area() const
{
    double p = this->perimeter() * 0.5;
    return sqrt(p*(p-x)*(p-y)*(p-z));
}


int main()
{
    Triangle triangle(1, 1, 1);
    triangle.print();
    cout << triangle.perimeter() << endl << setprecision(2) << triangle.area() << endl;
    return 0;
}
