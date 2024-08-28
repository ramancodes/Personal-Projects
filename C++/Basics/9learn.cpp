// namespaces

#include <iostream>

using namespace std;

namespace n1
{
    int val()
    {
        cout << "This is namespace ";
        return 1;
    }
}

namespace n2
{
    int c = 400;
    int val()
    {
        cout << "This is namespace ";
        return 2;
    }
}

int main()
{
    cout << n1::val() << endl;
    cout << n2::val() << endl;
    cout << n2::c << endl;
    return 0;
}