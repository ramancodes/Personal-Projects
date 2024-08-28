package Library.LibraryFunctions;

import java.sql.Connection;
import java.util.Scanner;

//user operation interface implementation
class UserOperations implements UserOperationInterface{
    Scanner scanner = new Scanner(System.in);
    CreateDatabase user = new CreateDatabase();
    AccessDatabase accessUser = new AccessDatabase();

    //method to issue a book by the user
    @Override
    public boolean issueBook(Connection connection) {
        System.out.println("\nEnter the BookID of the book you want to issue");
        Integer BookID = Integer.parseInt(scanner.nextLine());
        if (user.updateValue(BookID, 0, connection)){
            System.out.println("\n"+BookID+" is issued successfully");
            System.out.println("Book Details :");
            accessUser.showSingleValue(BookID, connection);
        } else {
            System.out.println("\n*Error!! Not Able to Issue the Book*");
        }
        return true;
    }

    //method to show all the books available to the user
    @Override
    public boolean availableBooks(Connection connection) {
        System.out.println("*****Here is the list of all the Books Available in the Library*****");
        accessUser.showValues(connection);
        return true;
    }

    //method to return a book by the user
    @Override
    public boolean returnBook(Connection connection) {
        System.out.println("\nEnter the BookID of the book you want to return");
        Integer BookID = Integer.parseInt(scanner.nextLine());
        if (user.updateValue(BookID, 1, connection)){
            System.out.println("\n"+BookID+" is returned successfully");
            System.out.println("Book Details :");
            accessUser.showSingleValue(BookID, connection);
        } else {
            System.out.println("\n*Error!! Not Able to Return the Book! Please Try Again*");
        }
        return true;
    }

    //method to show all the books availed by the user
    @Override
    public void myBook() {

    }
}
