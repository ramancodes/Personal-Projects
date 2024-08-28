#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v1;
    int choice, element, pos;
    // vector<int>::iterator itr = v1.begin();

    cout << "Choose from the following" << endl
         << "1. Add element at the end" << endl
         << "2. Delete element from the end" << endl
         << "3. Display all the elements" << endl
         << "0. Exit" << endl;

    do
    {
        cout << "Enter : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the element" << endl;
            cin >> element;
            v1.push_back(element);
            break;

        case 2:
            cout << "The last element is deleted" << endl;
            v1.pop_back();
            break;

        case 3:
            cout << "The elements are" << endl;
            display(v1);
            break;

        default:
            cout << "Wrong Input" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}