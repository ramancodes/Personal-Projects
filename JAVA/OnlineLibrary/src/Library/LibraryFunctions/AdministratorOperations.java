package Library.LibraryFunctions;

import java.sql.Connection;
import java.util.Scanner;

//administrator operations interface implementation
class AdministratorOperations implements AdmOperation {
    Scanner scanner = new Scanner(System.in);
    CreateDatabase user = new CreateDatabase();
    AccessDatabase accessUser = new AccessDatabase();

    //method to add a new book to the library by the admin
    @Override
    public boolean addBook(Connection connection) {
        Integer BookID;
        String BookName, Author;
        System.out.println("\nEnter the Book Details");
        System.out.print("\nBook ID : ");
        BookID = Integer.parseInt(scanner.nextLine());
        System.out.print("Book Name : ");
        BookName = scanner.nextLine();
        System.out.print("Author Name : ");
        Author = scanner.nextLine();
        if(user.insertValues(BookID, BookName, Author, 1, connection)){
            System.out.println("\n-The Books has been added successfully-");
            System.out.println("Book details-->");
            accessUser.showSingleValue(BookID, connection);
        } else {
            System.out.println("\n*Book Cannot be added to the list please try again*");
        }
        return true;
    }

    //method to remove a new book from the library by the admin
    @Override
    public boolean removeBook(Connection connection) {
        Integer BookID;
        System.out.println("\nEnter the Book ID you want to remove");
        BookID = Integer.parseInt(scanner.nextLine());
        System.out.println("\nBook Details --> ");
        accessUser.showSingleValue(BookID, connection);
        System.out.println("\n\nIs this the correct Book you want to delete ?");
        System.out.print("Enter 1 to confirm or\n Enter 0 to reject \n--> ");
        Integer choice1 = Integer.parseInt(scanner.nextLine());
        if (choice1==1||choice1==0) {
            if (user.deleteValue(BookID, connection)) {
                System.out.println("\n-The Book has been successfully deleted-");
            }
            else {
                System.out.println("\n*Error! Due to some internal issues the Book cannot be deleted*");
            }
        } else {
            System.out.println("\n*Okay! Book Deletion denied*");
        }
        return true;
    }

    //method to show all the available books in the library
    @Override
    public boolean availableBooks(Connection connection) {
        System.out.println("\n*****Here is the list of all the Books Available in the Library*****");
        accessUser.showValues(connection);
        return true;
    }
}
