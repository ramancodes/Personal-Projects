#include<iostream>
#include<map>
#include<string>

using namespace std;
 
int main()
{
    map<string, int> marksMap;
    marksMap["Raman"] = 9;
    marksMap["John"] = 8;
    marksMap["Jack"] = 7;

    marksMap.insert({{"Hello", 6}, {"Hey", 5}});

    map<string, int> ::iterator iter;
    for(iter=marksMap.begin(); iter!=marksMap.end(); iter++)
    {
        cout<<(*iter).first<<" "<<(*iter).second<<endl;
    }

return 0;
}