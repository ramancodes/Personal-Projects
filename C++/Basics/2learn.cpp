// dynamic constructor
// friend function
// aggregation
// new delete operator

#include<iostream>

using namespace std;

class Complex{
    int *real;
    int *img;
    friend Complex calc(Complex, Complex);    // friend function

    public:
        Complex()   // dynamic constructor
        {
            real = new int;
            img = new int;
        }

        Complex(int r, int i)   // dynamic constructor
        {
            real = new int;
            img = new int;

            *real = r;
            *img = i;
        }

    void show1st(Complex);
    void show();
    void del();
    ~Complex(){}
};

void Complex :: show1st(Complex o)
{
    cout<<"Complex Number : "<<*(o.real)<<" + "<<*(o.img)<<"!"<<endl;
}

void Complex :: show()
{
    cout<<"Complex Number : "<<*real<<" + "<<*img<<"!"<<endl;
}

void Complex :: del()
{
    delete real;
    delete img;
}

Complex calc(Complex o1, Complex o2)
{
    Complex o3;
    *(o3.real) = *(o1.real) + *(o2.real);
    *(o3.img) = *(o1.img) + *(o2.img);
    return o3;
}

int main()
{
    Complex obj1(2, 4), obj2(3, 8), obj3;

    obj3 = calc(obj1, obj2);

    obj2.show1st(obj1);
    obj2.show();
    obj3.show();

    obj1.del();
    obj2.del();
    obj3.del();

    return 0;
}