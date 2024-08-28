package com.company;
import java.util.Scanner;

public class Sum_N_Even_Numbers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the value of n : ");
        int n = sc.nextInt();
        int i = 0;
        int sum = 0;
        while (i<=n) {
                sum = sum + (i*2);
            i++;
        }

        System.out.println("The sum of first " + n + " even numbers is : " + sum);
    }
}
