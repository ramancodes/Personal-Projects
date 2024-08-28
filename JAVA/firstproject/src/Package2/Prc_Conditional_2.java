package Package2;

import java.util.Scanner;

public class Prc_Conditional_2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the year to check if it's leap year or not!");
        int year = Integer.parseInt(scanner.nextLine());
        if((year%4==0) && (year%100!=0) || (year%400==0)){
            System.out.println("The year "+year+" is a leap year");
        } else {
            System.out.println("The year "+year+" is a not leap year");
        }
    }

}
