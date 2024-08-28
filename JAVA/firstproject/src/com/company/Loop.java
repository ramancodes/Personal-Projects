package com.company;

import java.util.*;

public class Loop {
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter The limit for the series");
        int series = scan.nextInt();
        System.out.println("The series is :");
        for(int i = 0; i<=series; i++)
        {
            System.out.println(i);
        }
    }
}
