// this program converts kilometers to miles

package com.company;
import java.util.Scanner;

public class KiloConMiles {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter distance in kilometers");
        double kiloValue = scan.nextDouble();

        double milesValues = kiloValue * 0.621371;

        System.out.println(kiloValue + " kilometers" + " = " + milesValues + " miles");
    }
}
