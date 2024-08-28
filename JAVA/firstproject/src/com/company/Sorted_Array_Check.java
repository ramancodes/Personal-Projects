package com.company;

public class Sorted_Array_Check {
    public static void main(String[] args) {
        boolean check = true;
        //int[] arr = {20, 34, 56, 12, 78, 23, 50};
        int[] arr1 = {1, 2, 3, 5, 6, 8, 9};
        int min = Integer.MIN_VALUE;
        for(int element : arr1){
            if(min>element){
                check = false;
            }
            min = element;
        }

        System.out.println("The Array is sorted : "+check);
    }
}
