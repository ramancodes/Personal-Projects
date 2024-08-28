#include<iostream>
 
using namespace std;

class Complex{
    int real, img;
    public:
        Complex(){}
        Complex(int r, int i)
        {
            real = r;
            img = i;
        }

        Complex operator + (Complex obj)    //operator keyword is important
        {
            Complex objres;
            objres.real = real + obj.real;
            objres.img = img + obj.img;
            return objres;
        }

        void show()
        {
            cout<<real<<" + "<<img<<"!"<<endl;
        }
};

int main()
{
    Complex c1(4, 2), c2(3, 1), c3(2, 5), c4;
    c4 = c1+c2+c3;
    c4.show();

return 0;
}