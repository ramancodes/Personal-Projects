#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<list>

using namespace std;

class questions{
    list<string> quest;

public:
    void readyQues()
    {
        string q1 = "Question 1";
        quest.push_back(q1);
    }

    void printList()
    {
        for(auto i : quest)
        {
            cout<<i<<endl;
        }
    }
};

/*
class details{
    int data1, data2;
    string ques;

public:
    void getData()
    {
        cout<<"Enter your name"<<endl;
        getline(cin, name1);
        cout<<"Enter your No"<<endl;
        cin>>data1;
    }

    void enterFile()
    {
        fstream fio;
        fio.open("details.txt", ios::trunc | ios::out | ios::in);

        fio<<name1<<" "<<data1<<endl;

        fio.close();
        cout<<"Record Updated"<<endl;
    }
};
*/

int main()
{
    /*
    details stu1;
    stu1.getData();
    stu1.enterFile();
    */
   questions q1;
   q1.readyQues();
   q1.printList();
    return 0;
}