#include <iostream>
#include <list>

using namespace std;

void display(list<int> &li)
{
    list<int>::iterator it;
    for (it = li.begin(); it != li.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    list<int> lst;
    int choice, element;
    list<int>::iterator it = lst.begin();

    cout << "Choose from the following" << endl
         << "1. Insert Element at end" << endl
         << "2. Insert Element at front" << endl
         << "3. Insert Element at any position" << endl
         << "4. Delete from the front" << endl
         << "5. Delete front the end" << endl
         << "6. Delete an specific element" << endl
         << "7. Sort the list" << endl
         << "8. Reverse the list" << endl
         << "9. Clear the list" << endl
         << "10. Display the list" << endl
         << "0. EXIT" << endl;

    do
    {
        cout << "Enter : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element : ";
            cin >> element;
            lst.push_back(element);
            cout << "Inserted" << endl;
            break;
        case 2:
            cout << "Enter the element : ";
            cin >> element;
            lst.push_front(element);
            cout << "Inserted" << endl;
            break;
        case 3:
            int pos;
            cout << "Enter the element : ";
            cin >> element;
            cout << "Enter the position : ";
            cin >> pos;
            for (int i = 0; i < pos; i++)
                it++;
            lst.insert(it, element);
            cout << "Inserted" << endl;
            break;
        case 4:
            lst.pop_front();
            cout << "Deleted" << endl;
            break;
        case 5:
            lst.pop_back();
            cout << "Deleted" << endl;
            break;
        case 6:
            cout << "Enter the element : ";
            cin >> element;
            lst.remove(element);
            cout << "Deleted" << endl;
            break;
        case 7:
            lst.sort();
            cout << "Sorted" << endl;
            break;
        case 8:
            lst.reverse();
            cout << "Reversed" << endl;
            break;
        case 9:
            lst.clear();
            cout << "Cleared" << endl;
            break;
        case 10:
            display(lst);
            break;
        default:
            if (choice != 0)
                cout << "Wrong Choice" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}