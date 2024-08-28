/* pass or fail check program
 Condition -
 Pass if 40%+ aggregate and 33%+ in each subject
 */

package com.company;
import java.util.Scanner;

public class Prc_Conditional_1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Your Marks below out of 100 :-");
        System.out.print("Maths : ");
        int marks1 = scan.nextInt();
        System.out.print("Java : ");
        int marks2 = scan.nextInt();
        System.out.print("SQL : ");
        int marks3 = scan.nextInt();

        int aggregate = (marks1+marks2+marks3)*100/300;

        if(aggregate>=40) {
            if(marks1<33) {
                System.out.println("You need more practice in maths");
            }
            else if (marks2<33) {
                System.out.println("You need more practice in JAVA");
            }
            else if (marks3<33) {
                System.out.println("You need more practice in SQL");
            }
            else {
                System.out.println("You have passed the examination with a percentage of " + aggregate + "%.");
            }
        }
        else {
            System.out.println("Sorry!! You have failed the exam. You need more practice.");
        }
    }
}
