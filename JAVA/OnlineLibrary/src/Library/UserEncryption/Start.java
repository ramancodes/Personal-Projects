package Library.UserEncryption;

import Library.LibraryFunctions.ConnectionToDB;

import java.io.File;
import java.sql.Connection;
import java.util.Scanner;

public class Start {
    public Start(){
        Scanner scanner = new Scanner(System.in);
        Integer userAdmin, loginSignup;
        System.out.println("\nAre you a User or an Administrator? " +
                "\nChoose \n1 for User \n2 for Administrator");
        System.out.print("--> ");
        userAdmin = Integer.parseInt(scanner.nextLine());

        System.out.println("\nChoose " +
                "\n1 to Login \n2 to Register");
        System.out.print("--> ");
        loginSignup = Integer.parseInt(scanner.nextLine());

        op(userAdmin, loginSignup, scanner);
    }

    void op(Integer userAdmin, Integer loginSignup, Scanner scanner){
        File obj = new File("Library.db");
        if(obj.exists()) {
            Connection connection = ConnectionToDB.connectLibrary();
            switch (userAdmin) {
                case 1:
                    switch (loginSignup) {
                        case 1:
                            System.out.println("---USER LOGIN---");
                            Login login = new Login(scanner, userAdmin, connection);
                            break;
                        case 2:
                            System.out.println("---USER REGISTRATION---");
                            Register register = new Register(scanner, userAdmin, connection);
                            break;
                    }
                    break;

                case 2:
                    switch (loginSignup) {
                        case 1:
                            System.out.println("---ADMINISTRATOR LOGIN---");
                            Login login = new Login(scanner, userAdmin, connection);
                            break;
                        case 2:
                            System.out.println("---ADMINISTRATOR REGISTRATION---");
                            Register register = new Register(scanner, userAdmin, connection);
                            break;
                    }
                    break;
            }
        } else {
            System.out.println("\n*Error!! The file does not exists*");
        }
    }


}
