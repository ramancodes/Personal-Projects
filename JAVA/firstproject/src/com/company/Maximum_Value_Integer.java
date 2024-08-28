package com.company;

public class Maximum_Value_Integer {
    public static void main(String[] args) {
        int num = Integer.MIN_VALUE;
        int[] arr = {562, 2000, 3563, 56, 8262, 8363};
        for(int element : arr){
            if(element>num){
                num = element;
            }
        }

        System.out.println("The maximum number in the array is "+num);
    }
}
