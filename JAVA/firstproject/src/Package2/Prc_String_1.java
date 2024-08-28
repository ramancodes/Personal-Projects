package Package2;

import java.util.Scanner;

public class Prc_String_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the String : ");
        String str = sc.nextLine();
        System.out.println("Original String : " + str);
        System.out.println("String to lower case : " + str.toLowerCase());
    }
}
