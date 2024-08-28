package com.company;

import java.util.Scanner;

public class Fibonacci_Series {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int n1 = 0, n2 = 1;
        printFibonacci(n, n1, n2);
    }

    static void printFibonacci(int x, int n1 , int n2){
        System.out.print(n1+" "+n2+" ");
        while (x>2) {
            int n3 = n1+n2;
            n1 = n2;
            n2 = n3;
            System.out.print(n3+" ");
            x--;
            }
    }
}
