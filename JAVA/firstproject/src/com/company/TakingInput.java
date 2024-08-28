package com.company;
import java.util.Scanner;

public class TakingInput {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Please Enter Your First Name");
        String name = sc.next();
        System.out.println("Enter your First Number");
        int num1 = sc.nextInt();
        System.out.println("Enter your Second Number");
        int num2 = sc.nextInt();
        int sum = num1 + num2;
//        System.out.print("Hello ");
//        System.out.print(name);
//        System.out.print("! The Sum of ");
//        System.out.print(num1);
//        System.out.print(" And ");
//        System.out.print(num2);
//        System.out.print(" is ");
//        System.out.println(sum);
        System.out.println("Hello " + name + "! The Sum of " + num1 + " And " + num2 + " is " + sum);

    }
}
