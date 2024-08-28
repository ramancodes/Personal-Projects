// finding percentage of marks of CBSE subjects

package com.company;
import java.util.Scanner;

public class cbseMarksCalc {
    public static void main(String[] args){
        Scanner inp = new Scanner(System.in);
        System.out.println("Calculate Your CBSE Percentage Here");
        System.out.println("Enter Your Name");
        String name = inp.nextLine();
        System.out.println("Enter Your Roll No (Last 3 digits)");
        int rollNo = inp.nextInt();
        System.out.println("Enter the marks of the subjects out of 100");
        System.out.print("1. English : ");
        int eng = inp.nextInt();
        System.out.print("2. Hindi : ");
        int hin = inp.nextInt();
        System.out.print("3. Social Science : ");
        int ss = inp.nextInt();
        System.out.print("4. Science : ");
        int sci = inp.nextInt();
        System.out.print("5. Maths : ");
        int maths = inp.nextInt();
        int totalMarks = eng + hin + ss + sci + maths;
        float per = (totalMarks/500f)*100;

        System.out.println("Result :-");
        System.out.println("Name : " + name);
        System.out.println("Roll No. : " + rollNo);
        System.out.println("Total Marks : " + totalMarks);
        System.out.println("Percentage : " + per);

    }
}
