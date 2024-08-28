// program for sum of three numbers

package com.company;
import java.util.Scanner;

public class SumThreeNumbers {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.println("Enter three numbers");
        int num1 = input.nextInt();
        int num2 = input.nextInt();
        int num3 = input.nextInt();
        int sum = num1+num2+num3;
        System.out.println("Sum of three numbers : ");
        System.out.println(num1 + " + " + num2 + " + " + num3 + " = " + sum);
    }
}
