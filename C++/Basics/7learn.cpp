// binary operator overloading

#include <iostream>

using namespace std;

class Complex
{
    int real;
    int img;

public:
    Complex()
    {
        real = 0;
        img = 0;
    }
    Complex(int real, int img)
    {
        this->real = real;
        this->img = img;
    }

    void show()
    {
        cout<<"Number : "<<real<<" + "<<img<<"!"<<endl;
    }

    Complex operator+ (const Complex &ob)
    {
        Complex obj;
        obj.real = this->real + ob.real;
        obj.img = this->img + ob.img;
        return obj;
    }
};

int main()
{
    int r1, r2, i1, i2;
    cout<<"Enter the first complex number"<<endl;
    cin>>r1>>i1;

    cout<<"Enter the second complex number"<<endl;
    cin>>r2>>i2;

    Complex num1(r1, i1), num2(r2, i2), num3;

    num3 = num1 + num2;

    num1.show();
    num2.show();
    num3.show();

    return 0;
}