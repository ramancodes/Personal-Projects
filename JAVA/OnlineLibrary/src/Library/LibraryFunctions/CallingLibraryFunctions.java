package Library.LibraryFunctions;

import java.sql.Connection;
import java.util.Scanner;

class CallingFunctions{
    Scanner scanner = new Scanner(System.in);
    UserOperationInterface userSide = new UserOperations();
    AdmOperation adminSide = new AdministratorOperations();

    //user dashboard operations
    void user(Connection connection){
        Integer choice;
        System.out.println("\n\nWELCOME TO USER DASHBOARD");
        System.out.println("Here are the options you can do with the library");
        do {
            System.out.println("\n Options : ");
            System.out.println("1. Show All The Available Books In The Library");
            System.out.println("2. Issue a Book From The Library");
            System.out.println("3. Return a Book To The Library");
            System.out.println("0. To exit");
            System.out.print("ENTER ANY OPTION : ");
            choice = Integer.parseInt(scanner.nextLine());
            switch (choice) {
                case 1:
                    if (userSide.availableBooks(connection)) {
                    } else {
                        System.out.println("\n*Internal Error Please Try Again*");
                    }
                    break;
                case 2:
                    if (userSide.issueBook(connection)) {
                    } else {
                        System.out.println("\n*Internal Error Please Try Again*");
                    }
                    break;

                case 3:
                    if (userSide.returnBook(connection)) {
                    } else {
                        System.out.println("\n*Internal Error Please Try Again*");
                    }
                    break;
                case 0:
                    System.out.println("\n*Thank You Visit Again*");
                    break;

                default:
                    System.out.println("\n*Sorry you have chosen the wrong option*");
                    break;
            }
        }while (choice!=0);
    }

    //admin dashboard operations
    void admin(Connection connection){
        Integer choice;
        System.out.println("\n\nWELCOME TO ADMINISTRATOR DASHBOARD");
        System.out.println("Here are the options you can do with the library");
        do {
            System.out.println("\n\n1. Show All The Available Books In The Library");
            System.out.println("2. Add a Book To The Library");
            System.out.println("3. Remove a Book From The Library");
            System.out.println("0. To exit");
            System.out.print("ENTER ANY OPTION : ");
            choice = Integer.parseInt(scanner.nextLine());
            switch (choice) {
                case 1:
                    if (adminSide.availableBooks(connection)) {
                    } else {
                        System.out.println("\n*Internal Error Please Try Again*");
                    }
                    break;

                case 2:
                    if (adminSide.addBook(connection)) {
                    } else {
                        System.out.println("\n*Internal Error Please Try Again*");
                    }
                    break;

                case 3:
                    if (adminSide.removeBook(connection)) {
                    } else {
                        System.out.println("\n*Internal Error Please Try Again*");
                    }
                    break;
                case 0:
                    System.out.println("\n*Thank You Visit Again*");
                    break;

                default:
                    System.out.println("\n*Sorry you have chosen the wrong option*");
                    break;

            }
        }while (choice!=0);
    }
}

//home screen dashboard
class CallingLibraryFunctions {
//    Connection connection = ConnectionToDB.connectLibrary();

    public CallingLibraryFunctions(Integer userAdmin, Connection connection){
        CallingFunctions callingFunctions = new CallingFunctions();
        Scanner scanner = new Scanner(System.in);

        if(userAdmin==1){
            callingFunctions.user(connection);
        }
        else if(userAdmin == 2) {
            callingFunctions.admin(connection);
        }
    }
}
