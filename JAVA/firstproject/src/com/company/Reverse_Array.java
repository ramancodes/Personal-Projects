package com.company;

import java.util.Scanner;

public class Reverse_Array {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[5];
        int l = arr.length;
        int n = Math.floorDiv(arr.length, 2);

        System.out.println("Original Array : ");
        for(int i=0;i<arr.length;i++) {
            arr[i] = sc.nextInt();
        }

        System.out.println("Reversed Array : ");
        for(int i=0; i<n; i++){
            int temp = arr[i];
            arr[i] = arr[l-i-1];
            arr[l-i-1] = temp;
        }

        for(int element : arr){
            System.out.println(element);
        }
    }
}
