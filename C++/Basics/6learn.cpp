// unary operator overloading

#include <iostream>

using namespace std;

class Dist
{
    int metres;
    int centimeteres;

public:
    Dist()
    {
        metres = 0;
        centimeteres = 0;
    }
    Dist(int m, int cm)
    {
        metres = m;
        centimeteres = cm;
    }
    void show()
    {
        cout << metres << " m " << centimeteres << " cm" << endl;
    }

    Dist operator-()
    {
        metres--;
        centimeteres--;
        return Dist(metres, centimeteres);
    }

    Dist operator+()
    {
        metres++;
        centimeteres++;
        return Dist(metres, centimeteres);
    }
};

int main()
{
    Dist ob(10, 9), ob1(2, 8);
    cout << "The original data " << endl;
    ob.show();
    ob1.show();

    int ch;
    do
    {
        cout << endl
             << "Choose:" << endl
             << "1. Increment" << endl
             << "2. Decrement" << endl
             << "0. Exit" << endl
             << endl
             << "Enter : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            +ob;
            +ob1;
            ob.show();
            ob1.show();
            break;

        case 2:
            -ob;
            -ob1;
            ob.show();
            ob1.show();
            break;

        default:
            if (ch != 0)
                cout << "Wrong Input" << endl;
            break;
        }
    } while (ch != 0);

    return 0;
}