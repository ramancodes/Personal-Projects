// parametric polymorphism

#include<iostream>
 
using namespace std;

class Average
{
    int res;

public:
    void getAvg(int x, int y)   // two functions with same name
    {
        res = (x+y)/2;
        cout<<"Average = "<<res<<endl;
    }

    void getAvg(int x, int y, int z)
    {
        res = (x+y+z)/3;
        cout<<"Average = "<<res<<endl;
    }
};

int main()
{
    Average obj;
    obj.getAvg(3, 3);
    obj.getAvg(2, 4, 6);

return 0;
}