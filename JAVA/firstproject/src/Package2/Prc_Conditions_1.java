package Package2;

import java.util.Scanner;

public class Prc_Conditions_1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Hello Customer, Enter Your Income to know you Income Tax");
        int income = Integer.parseInt(scanner.nextLine());

        if(income<=250000){
            System.out.println("You don't have to pay any tax");
        } else if (income<=500000) {
            System.out.println("Your Income Tax is " + (income*0.05));
        } else if (income<=1000000) {
            System.out.println("Your Income Tax is " + (income*0.2));
        } else {
            System.out.println("Your Income Tax is " + (income*0.3));
        }
    }
}
