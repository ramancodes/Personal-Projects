package Library.UserEncryption;

import java.sql.Connection;
import java.util.Scanner;
import Library.LibraryFunctions.StartLibrary;

class Login {
    Login(Scanner scanner, Integer userAdmin, Connection connection){
        String libraryId, password;
        int i = 3;
        boolean nextAttempt = true;
        DatabaseOperations databaseOperations = new DatabaseOperations();
        while (nextAttempt) {
            System.out.print("Library ID : ");
            libraryId = scanner.nextLine();
            System.out.print("Password : ");
            password = scanner.nextLine();

            if (databaseOperations.Login(userAdmin, libraryId, password, connection)) { //check credentials of either user or admin
                System.out.println("Login Successful");
                StartLibrary startLibrary = new StartLibrary(userAdmin, connection);
                nextAttempt = false;
                //code here
            } else {
                i--;
                System.out.println("\n\nWrong Credentials");
                System.out.println("You have "+i+" attempts left");
            }

            if (i<3 && nextAttempt == true){
                System.out.println("Forgot Your Password?\n Do You Want To Reset?");
                System.out.println(" 1. Y for Yes\n 2. N for No");
                String p = scanner.nextLine();
                if (p.equalsIgnoreCase("Y")){
                    // forgot password code
                    System.out.println("In Process");
                }
            }
        }
        if(i==0){
            System.out.println("***You exceeded the no of attempts!!*** \n***Try Again later***");
        }
    }
}
