package com.company;
import java.util.Locale;
import java.util.Scanner;

public class StringMethods {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Your Name");
        String name = scan.nextLine();

        System.out.println("Your Name : " + name);
        System.out.println("The length of the string is : " + name.length());
        System.out.println("The Lowercase of the string is : " + name.toLowerCase(Locale.ROOT));
        System.out.println("The Uppercase of the string is : " + name.toUpperCase(Locale.ROOT));

    }
}
