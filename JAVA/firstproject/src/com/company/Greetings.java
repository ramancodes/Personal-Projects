// this program greets the user

package com.company;
import java.util.Scanner;

public class Greetings {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        System.out.print("Enter Your Name : ");
        String name = inp.nextLine();
        System.out.println("Hello " + name + "! Have A Nice Day!!!!!!!");
    }
}
