/*
Roc Scissor Paper Game -
Rock - <4
Paper - 4<7
Scissor - 7<
 */

package com.company;
import java.util.Random;
import java.util.Scanner;

public class Rock_Paper_Scissor_Game {
    public static void main(String[] args) {

        //system turn
        Random rn = new Random();
        int number = rn.nextInt(1, 10);
        String os;
        if(number < 4) {
            os = "Rock";
        } else if (number < 7) {
            os = "Paper";
        } else {
            os = "Scissor";
        }

        //user turn
        Scanner sc = new Scanner(System.in);
        System.out.println("Welcome to the Rock Paper Scissor Game");
        System.out.println("Choose from the following:\n Rock\n Paper\n Scissor");
        System.out.print("Enter : ");
        String user = sc.next();

        //game starts
        if(os.equalsIgnoreCase(user)) {
            System.out.println("You both have chosen the same option : " + os);
            System.out.println("There a tie please play again!!");
        } else if (os.equalsIgnoreCase("Rock") && user.equalsIgnoreCase("Paper")) {
            System.out.println("User Wins!!");
        } else if (os.equalsIgnoreCase("Rock") && user.equalsIgnoreCase("Scissor")) {
            System.out.println("Operating System Wins!!");
        } else if (os.equalsIgnoreCase("Paper") && user.equalsIgnoreCase("Scissor")) {
            System.out.println("User Wins!!");
        } else if (os.equalsIgnoreCase("Paper") && user.equalsIgnoreCase("Rock")) {
            System.out.println("Operating System Wins!!");
        } else if (os.equalsIgnoreCase("Scissor") && user.equalsIgnoreCase("Rock")) {
            System.out.println("User Wins!!");
        } else if (os.equalsIgnoreCase("Scissor") && user.equalsIgnoreCase("Paper")) {
            System.out.println("Operating System Wins!!");
        }

        System.out.println("Os = " + os);
        System.out.println("User = " + user);
    }
}
