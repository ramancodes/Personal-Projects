/*
Project Name : Library Management System
Author : Raman Kumar Manjhi
Project Duration : 8th Nov 2022 - 10th Nov 2022

Description -
This is the most basic type of library management system created by using the basic knowledge of programming languages.
1. Programming Language Used :
    --> JAVA
2. Database Language Used :
    --> SQLite

Operations performed on this Online Library -
User Side -
1. ShowAvailableBooks() - for displaying all the books available in the database from the user side.
2. IssueBook() - for issuing a book to the user using the BookID.
3. ReturnBook() - for returning the book issued by the user back to the library database.

Administrator Side -
1. ShowAvailableBooks() - for displaying all the books available in the database from the admin side.
2. ShowSingleBook() - for displaying all the books available in the database from the admin side.
3. AddBook() - for adding a new book to the library database.
4. RemoveBook() - for removing a book from the library database.

Note -
According to this library one user can issue only one book at one time.
Availability of books are marked with 0 & 1.
1 : Available
0 : Not Available
 */

/*
Pending -
1. Book Count
2. Front End
3. File Import from CSV
4. Search
 */


import Library.UserEncryption.Start;

public class Main {
    public static void main(String[] args) {
        System.out.println("****************************************************");
        System.out.println("        WELCOME TO RAMAN'S ONLINE LIBRARY           ");
        System.out.println("****************************************************");
        Start start = new Start();

    }
}