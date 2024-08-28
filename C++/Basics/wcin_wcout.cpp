#include<iostream>

using namespace std;

int main()
{
    wcout<<"Hello"<<endl;
    int *a = new int;
    wcin>>*a;
    cout<<*a<<endl;
    delete a;
    cout<<*a<<endl;
}