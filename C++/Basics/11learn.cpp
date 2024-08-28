// exception handling

#include<iostream>
 
using namespace std;

double divison(double a, double b)
{
    if(b==0)
    {
        throw "Division cannot be performed!";
    }

    return a/b;
}

int main()
{
    double a, b;
    double z;
    cout<<"Enter two numbers"<<endl;
    cin>>a>>b;

    try
    {
        z = divison(a, b);
        cout<<"Diviion : "<<z<<endl;
    }
    catch(const char* msg)
    {
        cerr<<msg<<endl;
    }

return 0;
}