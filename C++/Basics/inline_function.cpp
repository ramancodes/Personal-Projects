#include <iostream>

using namespace std;

inline int add(int a, int b)
{
    return a + b;
}

inline int sub(int a, int b)
{
    return a - b;
}

inline int mul(int a, int b)
{
    return a * b;
}

inline int division(int a, int b)
{
    return a / b;
}

void choice(char op, int a, int b)
{
    switch (op)
    {
    case '+':
        cout << "ADDITION = " << add(a, b) << endl;
        break;
    case '-':
        cout << "SUBSTRACTION = " << sub(a, b) << endl;
        break;
    case '*':
        cout << "MULTIPLICATION = " << mul(a, b) << endl;
        break;
    case '/':
        cout << "DIVISION = " << division(a, b) << endl;
        break;
    default:
        cout << "Sorry Wrong input" << endl;
        break;
    }
}

int main()
{
    char check = 'y';

    while (check == 'y')
    {
        int a, b;
        char op;
        cout << "Enter two numbers along with the operation(eg - a+b)" << endl;
        cin >> a;
        cin >> op;
        cin >> b;
        choice(op, a, b);
        cout << "Do you want to continue? (y/n)" << endl;
        cin >> check;
    }
    if (check != 'y')
    {
        cout << "Thank You!" << endl;
    }

    return 0;
}