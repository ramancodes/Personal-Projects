package com.company;
import java.util.Scanner;

public class Multiplication_Table {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number : ");
        int number = sc.nextInt();

        for(int i = 1; i<=10; i++) {
            System.out.println(number + " x " + i + " = " + number*i);
        }

    }
}
