package Package2;

import java.util.Scanner;

public class Prc_String_3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the String : ");
        String str = scanner.nextLine();
        System.out.println("Given String : " + str);
        boolean whiteSpace2 = str.contains("  ");
        boolean whiteSpace3 = str.contains("   ");

        System.out.println("Double whitespace available : " + whiteSpace2);
        System.out.println("Triple whitespace available : " + whiteSpace3);
    }
}
