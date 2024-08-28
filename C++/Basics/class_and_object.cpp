#include <iostream>

using namespace std;

class Complex
{ //class defination
    int x = 0, y = 0;
    float a = 0, b, c;
    float d = 0, e, f;

public:
    Complex() {}                  //default constructor
    Complex(int, int);            //parameterised constructor
    Complex(float, float, float); //parameterised constructor
    Complex(Complex &obj);        // copy constructor
    void print();
    friend Complex sum(Complex, Complex); //friend function
};

Complex::Complex(int x, int y)
{
    this->x = x;
    this->y = y;
}

Complex::Complex(float x, float y = 0, float z = 0)
{
    a = x;
    b = y;
    c = z;
}

Complex::Complex(Complex &obj)
{
    d = obj.a;
    e = obj.b;
    f = obj.c;
}

void Complex::print()
{
    if (a == 0 && d == 0)
    {
        cout << "The values are" << endl
             << "X = " << x << endl
             << "Y = " << y << endl
             << "Complex Number = " << x << " + " << y << "!" << endl;
    }
    else if (x == 0 && d == 0)
    {
        cout << "The value is" << endl
             << "A = " << a << endl
             << "B = " << b << endl
             << "C = " << c << endl;
    }
    else
    {
        cout << "The value is" << endl
             << "D = " << d << endl
             << "E = " << e << endl
             << "F = " << f << endl;
    }
}

Complex sum(Complex a, Complex b)
{
    Complex obj3;
    obj3.x = a.x + b.x;
    obj3.y = a.y + b.y;
    return obj3;
}

int main()
{
    /*
    Complex obj1(4, 2), obj2(3, 1), obj3;       // creating objects 
    obj3 = sum(obj1, obj2);

    obj1.print();
    obj2.print();
    obj3.print();
    */

    Complex obj[5]; // creating array of object
    obj[0] = Complex(4, 2);
    obj[1] = Complex(3, 1);

    obj[2] = sum(obj[0], obj[1]);

    for (int i = 0; i < 3; i++)
    {
        obj[i].print();
    }

    obj[3] = Complex(4.5);
    obj[3].print();

    obj[4] = Complex(obj[3]);
    obj[4].print();

    return 0;
}