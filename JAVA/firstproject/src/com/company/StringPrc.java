package com.company;
import java.util.Scanner;

public class StringPrc {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Your Message: ");
        String name = sc.nextLine();
        int a, b;
        System.out.print("Enter the first value: ");
        a = sc.nextInt();
        System.out.print("Enter the second value: ");
        b = sc.nextInt();
        System.out.printf("The message is: %s and the values are %d, %d.", name, a, b);
//        System.out.println(name);
    }
}
