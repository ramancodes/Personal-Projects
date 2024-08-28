package com.company;

import java.util.Random;
import java.util.Scanner;

public class casinoGames {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random rn = new Random();

        //user input
        System.out.println("---Welcome to Casino Game---");
        System.out.print("Enter Your Number to play the Game : ");
        int user = sc.nextInt();

        //game process
        int roundNumber = rn.nextInt(10, 20);
        int i = 1;

        //round loop
        while (i<=roundNumber) {
            //round number
            if(i==1) {
                System.out.println("1st Round --> ");
            } else if(i==2) {
                System.out.println("2nd Round --> ");
            } else if(i==3) {
                System.out.println("3rd Round --> ");
            } else {
                System.out.println(i + "th Round -- >");
            }

            //last round check
            if(i==roundNumber) {
                int luckyNumber = rn.nextInt(1, 10);
                int j = printNumber(luckyNumber);

                //luck check
                if(j==user) {
                    System.out.println("Wooohooo!!! You won a gift voucher of Rs 1000");
                } else {
                    System.out.println("OOPS Sorry!! Better Luck Next Time");
                }
            } else {
                printNumber(10);
            }
            i++;
        } //round loop
    } //main function

    public static int printNumber(int n) {
        int i = 1;
        while (i<=n) {
            System.out.print(i + "\t");
            i++;
        }
        System.out.println("");
        return i;
    } //print Numbers Method

}