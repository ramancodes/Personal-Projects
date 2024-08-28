package com.company;

import java.util.Scanner;

public class Sum_Two_Matrices {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] arr1 = new int[2][3];
        int[][] arr2 = new int[2][3];
        int[][] arr3 = new int[2][3];

        //1st matrix values
        System.out.println("Enter the Value of matrix 1 : ");
        for(int i =0;i<arr1.length;i++) {
            for(int j =0;j<arr1[i].length;j++){
                System.out.print("arr1["+i+"]["+j+"] : ");
                arr1[i][j] = sc.nextInt();
            }
        }

        //2nd matrix values
        System.out.println("Enter the Value of matrix 2 : ");
        for(int i =0;i<arr2.length;i++) {
            for(int j =0;j<arr2[i].length;j++){
                System.out.print("arr2["+i+"]["+j+"] : ");
                arr2[i][j] = sc.nextInt();
            }
        }

        //sum of both matrices
        for(int i =0;i<arr3.length;i++) {
            for(int j =0;j<arr3[i].length;j++){
                arr3[i][j] = arr1[i][j] + arr2[i][j];
            }
        }

        //printing of the new matrix
        System.out.println("New Matrix -->");
        for(int i =0;i<arr2.length;i++) {
            for(int j =0;j<arr2[i].length;j++){
                System.out.print(arr3[i][j]);
                System.out.println("\t");
            }
            System.out.println("");
        }
    }
}
