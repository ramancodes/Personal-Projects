// file handling

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    // using ofstream and ifstream

    string s = "Raman";
    string a;

    ofstream fout;
    fout.open("sample.txt");
    fout<<s<<endl;
    fout.close();

    ifstream fin;
    fin.open("sample.txt");
    fin>>a;
    fin.close();

    cout<<a<<endl;

    // using fstream

    string q = "Manjhi";
    string b;

    fstream fio;

    fio.open("sample1.txt", ios::trunc | ios::in | ios::out);

    fio<<q<<endl;

    fio.seekg(0, ios::beg);

    fio>>b;

    fio.close();

    cout<<b<<endl;

return 0;
}