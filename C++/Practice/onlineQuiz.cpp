#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class questions
{
    vector<string> q;
    vector<string> a;
    void qusList()
    {
        q.push_back("Q1. What is your name");
        q.push_back("Q2. What is your age");
        q.push_back("Q3. What is your address");
        q.push_back("Q4. What is your phoneno");
    }

    void ansList()
    {
        string ans;
        for (auto const i : q)
        {
            cout << i << endl;
            cout << "Enter : ";
            getchar();
            cin>>ans;
            a.push_back(ans);
        }
    }

public:
    void startQuiz()
    {
        qusList();
        cout << endl
             << "Let's GO....." << endl
             << endl;
        ansList();
    }

    void showRes()
    {
        int count = 0;
        for(auto const i : q)
        {
            cout<<i<<endl;
            cout<<"Answer : "<<a.at(count++)<<endl;
        }
    }
};

int main()
{
    questions test1;
    string choice;
    cout<<"Do you want to start the quiz"<<endl;
    cin>>choice;
    if(choice == "YES" || choice == "Yes" || choice == "yes")
    {
        test1.startQuiz();
    }
    else
    {
        cout<<"Okay No issues"<<endl;
    }

    cout<<endl<<"Thanks! Quiz is completed"<<endl;

    cout<<endl<<"Do you want to view your result"<<endl;
    cin>>choice;
    if(choice == "YES" || choice == "Yes" || choice == "yes")
    {
        test1.showRes();
    }
    else
    {
        cout<<"Thank You"<<endl;
    }

    return 0;
}