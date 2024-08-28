/*
Name - Raman Kumar Manjhi
Date - 19th Feb 2022
Program Name -  Movie Ticket Eligibilty checker.
Program Description - The program shows the list of movies and displays the output if the user is eligible to watch the movie or not according to the age of the user and the user's parent's permission.
*/                        

#include <iostream>
using namespace std;

int main()
{
    int num, age;
    char choice;
    cout << "Welcome to Theatre\n";
    cout << "\nWe are currently showing the following films:";
    cout << "\n1. Aladdin (G)";
    cout << "\n2. Jumanji (PG)";
    cout << "\n3. Mrs. Doubtfire (PG-13))";
    cout << "\n4. The Birdcage (R)\n";
    cout << "\nEnter the number of the movie you would like to see : ";
    cin >> num;

    if (num != 1)
    {
        cout << "\nWhat is your age in years?" << endl;
        cin >> age;
    }

    switch (num)
    {
    case 1:
        cout << "\nYou have selected Aladdin" << endl;
        cout << "\nGreat! Enjoy The film!" << endl;
        break;

    case 2:
        cout << "\nYou have selected Jumanji - does a parent know you are seeing this? Enter Y for yes or N for no.";
        cin >> choice;
        if (choice == 'Y' || choice == 'y')
            cout << "\nGreat! Enjoy The film!" << endl;
        else
            cout << "\nSorry you need your parent permission to view this film" << endl;
        break;

    case 3:
        if (age >= 13)
        {
            cout << "\nYou have selected Mrs. Doubtfire" << endl;
            cout << "\nGreat! Enjoy The film" << endl;
        }
        else
        {
            cout << "\nYou are not old enough to view this movie alone - do you have a parent comming with you? Enter Y for yes and N for no.";
            cin >> choice;
            if (choice == 'Y' || choice == 'y')
                cout << "\nGreat! Enjoy The film!" << endl;
            else
                cout << "\nSorry you need your parent permission to view this film" << endl;
        }
        break;

    case 4:
        if (age >= 17)
        {
            cout << "\nYou have selected The Birdcage" << endl;
            cout << "\nGreat! Enjoy The film!" << endl;
        }
        else
        {
            cout << "\nYou are not old enough to view this movie alone - do you have a parent comming with you? Enter Y for yes and N for no";
            cin >> choice;
            if (choice == 'Y' || choice == 'y')
                cout << "\nGreat! Enjoy The film!" << endl;
            else
                cout << "\nSorry you need your parent permission to view this film" << endl;
        }
        break;
    }
    return 0;
}