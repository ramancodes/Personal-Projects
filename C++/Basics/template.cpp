#include <iostream>

using namespace std;

template <class T, int size>
class Array
{
    T arr[size];

public:
    Array(T a[])
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = a[i];
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    Array<int, 10> obj(arr);
    obj.print();

    char arr1[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    Array<char, 10> obj1(arr1);
    obj1.print();
    
    return 0;
}