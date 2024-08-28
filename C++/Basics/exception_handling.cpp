#include<iostream>
 
using namespace std;
 
int main()
{
    int a, b, res;
    cout<<"Enter two numbers"<<endl;
    cin>>a>>b;

    try
    {
        if(b == 0)
        {
            throw b;
        }
        res = a/b;
        cout<<"Result = "<<res<<endl;
    }
    catch(int den)
    {
        cout<<"Division is not possible with "<<den<<endl;
    }
    
return 0;
}