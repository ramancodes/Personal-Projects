// inheritance
// polymorphism
// virtual class

#include <iostream>

using namespace std;

class Student
{
    string name;

public:
    Student() {}
    Student(string n)
    {
        name = n;
    }

    string retname()
    {
        return name;
    }
};

class academics : public virtual Student
{
    int marks;

public:
    academics(int m)
    {
        marks = m;
    }

    int retmarks()
    {
        return marks;
    }
};

class sports : public virtual Student
{
    int score;

public:
    sports(int s)
    {
        score = s;
    }

    int retscore()
    {
        return score;
    }
};

class Total : public academics, public sports
{
    int tot;

public:
    Total(string n, int m, int s) : Student(n), academics(m), sports(s)
    {
    }

    void show();
};

void Total ::show()
{
    cout << "NAME : " << retname() << endl
         << "MARKS : " << retmarks() << endl
         << "SCORE : " << retscore() << endl
         << "TOTAL : " << retmarks() + retscore() << endl;
}

int main()
{
    Total obj("Raman", 90, 85);
    obj.show();

    return 0;
}