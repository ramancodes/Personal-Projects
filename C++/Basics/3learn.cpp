// inheritance
// abstract data type
// abstract class
// pure virtual functions

#include <iostream>

using namespace std;

class Car // abstract class
{
public:
    virtual void start() = 0;   // pure virtual class or abstract data type
    virtual void goAhead() = 0; // pure virtual class or abstract data type
    virtual void goBack() = 0;  // pure virtual class or abstract data type
    virtual void stop() = 0;    // pure virtual class or abstract data type
};

class Engine : Car // single inheritance
{
public:
    void start()
    {
        cout << "The car is Started" << endl;
    }

    void stop()
    {
        cout << "The is stopped" << endl;
    }

    void goAhead()
    {
        cout << "Moving Ahead" << endl;
    }

    void goBack()
    {
        cout << "Going Back" << endl;
    }
};

int main()
{
    int check;
    Engine obj;
    cout<< "Your car is ready" << endl;
    do
    {
        cout << endl
             << "1. Start" << endl
             << "2. Stop" << endl
             << "3. Go Ahead" << endl
             << "4. Go Back" << endl
             << "5. Exit" << endl;
        cout << "Enter : ";
        cin >> check;
        switch (check)
        {
        case 1:
            obj.start();
            break;

        case 2:
            obj.stop();
            break;

        case 3:
            obj.goAhead();
            break;

        case 4:
            obj.goBack();
            break;

        default:
            if (check != 5)
                cout << "Wrong Input" << endl;
            break;
        }
    } while (check != 5);

    return 0;
}