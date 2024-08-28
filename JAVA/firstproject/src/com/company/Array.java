package com.company;

import java.util.Scanner;

public class Array {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter The number to search");
        int user = sc.nextInt();

        int[] arr = {10, 12, 34, 45, 56, 67, 78, 89 ,90};

        for(int i = 0; i<arr.length;i++){
            if(user==arr[i]) {
                System.out.println("Found!!");
                break;
            }
            if((i+1)==arr.length){
                System.out.println("Not Found!!");
            }
        }

    }
}
