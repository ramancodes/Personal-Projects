package com.company;
import java.util.Scanner;

public class FirstString {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter The First string you want : ");
        String str1 = scan.nextLine();

        System.out.println("Length of the string is : " + str1.length());
        System.out.println("Uppercase String is : " + str1.toUpperCase());
        System.out.println("Lowercase String is : " + str1.toLowerCase());
        System.out.println("When \'h\' is replaced with \'l\' : " + str1.replace('h', 'l'));

        System.out.print("Enter The Second string you want : ");
        String str2 = scan.nextLine();

        System.out.println("Length of the string is : " + str2.length());
        System.out.println("Uppercase String is : " + str2.toUpperCase());
        System.out.println("Lowercase String is : " + str2.toLowerCase());
        System.out.println("When \'a\' is replaced with \'s\' : " + str2.replace('a', 's'));

        System.out.println("Two strings equality check : " + str2.equals(str1));
        System.out.println("Two strings equality check : " + str2.equalsIgnoreCase(str1));

    }
}
