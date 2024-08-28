package Package2;

import java.util.Scanner;

public class Prc_String_2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the String : ");
        String str = scanner.nextLine();
        System.out.println("Original String : " + str);
        System.out.println("String to lower case : " + str.replace(" ", "_"));
    }
}
