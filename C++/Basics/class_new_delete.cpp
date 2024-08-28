#include <iostream>

using namespace std;

class Complex
{ //class defination
    int x, y;

public:
    Complex() {}       //default constructor
    Complex(int, int); //parameterised constructor
    void print(string);
    friend Complex sum(Complex, Complex); //friend function
    ~Complex() {}
};

Complex::Complex(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Complex::print(string T)
{
    cout << "The " <<T <<" values are" << endl
         << "X = " << x << endl
         << "Y = " << y << endl
         << "Complex Number = " << x << " + " << y << "!" << endl;
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
    Complex *obj, *res, *temp, *temp2;

    // memory allocation
    obj = new Complex[3];

    obj[0] = Complex(4, 2);
    obj[1] = Complex(3, 1);
    obj[2] = Complex(9, 5);

    res = new Complex[2];
    temp = res;
    temp2 = obj;

    for (int i = 0; i < 2; i++)
    {
        *res = sum(*(obj + i), *(obj + i + 1));
        res++;
    }

    for (int i = 0; i < 3; i++)
    {
        obj->print("complex");
        obj++;
    }

    for (int i = 0; i < 2; i++)
    {
        temp->print("sum");
        temp++;
    }

    delete obj, res;
    
    return 0;
}