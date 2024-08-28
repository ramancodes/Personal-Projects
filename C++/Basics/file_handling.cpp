#include<iostream>
#include<fstream>

using namespace std;
 
int main()
{
    int a = 4, b = 8;
    ifstream in;
    ofstream out;
    out.open("file.text");
    out<<a<<endl;
    out<<b;
    out.close();
    int d, e;
    in.open("file.text");
    in>>d>>e;
    in.close();
    cout<<d<<"\t"<<e<<endl;
return 0;
}