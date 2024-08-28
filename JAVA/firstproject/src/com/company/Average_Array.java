package com.company;

import java.util.Scanner;

public class Average_Array {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        //no of students
        System.out.print("Enter the no of students :");
        int stuNum = sc.nextInt();

        //marks of students
        int[] marks = new int[stuNum];
        int sum = 0;
        System.out.println("Enter the marks of students -->");
        for (int i =0; i<marks.length;i++) {
            System.out.print("Student "+(i+1)+" : ");
            marks[i] = sc.nextInt();
        }

        for (int element : marks){
            sum = sum+element;
        }

        System.out.println("Average of the marks of "+stuNum+" students = "+sum/stuNum);
    }
}
