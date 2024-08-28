package Library.UserEncryption;

import java.sql.Connection;
import java.util.Scanner;

class Register {
    Register(Scanner scanner, Integer userAdmin, Connection connection) {
        String libraryId, password, name;
        DatabaseOperations databaseOperations = new DatabaseOperations();
        System.out.println("\n\nEnter Details To Register in Raman's Library");
        System.out.print("Enter You Name : ");
        name = scanner.nextLine();
        System.out.print("library ID : ");
        libraryId = scanner.nextLine();
        System.out.print("Password : ");
        password = scanner.nextLine();

        if (databaseOperations.Registration(userAdmin, name, libraryId, password, connection)) { //Check if the insert is done
            System.out.println("Registration Successful");
            Login login = new Login(scanner, userAdmin, connection);
            //code here
        } else {
            System.out.println("***Internal Error in Registration!!*** \n***Try Again later***");
        }
    }
}
