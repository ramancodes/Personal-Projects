package com.company;
import java.util.Scanner;

public class IntegerCheck {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        System.out.print("Enter The Characters : ");
        System.out.println("Is the Entered character integer ? " + inp.hasNextInt());
    }
}
