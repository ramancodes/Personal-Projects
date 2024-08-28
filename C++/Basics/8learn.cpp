// template function
// genric class

#include <iostream>

using namespace std;

template <class T>  // template class
class Add   // generic class
{
    T num1, num2;
    inline T retsum()
    {
        return num1 + num2;
    }

public:
    Add(T n1, T n2)
    {
        num1 = n1;
        num2 = n2;
    }

    void DisplayData()
    {
        cout << "Add = " << retsum() << endl;
    }
};

template<class X> // template function
void func(X a)
{
    cout<<"The value of x is : "<<a<<endl;
}

int main()
{
    Add<int> o(2, 6);
    o.DisplayData();

    func("Raman");
    return 0;
}