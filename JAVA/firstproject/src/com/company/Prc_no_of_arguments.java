package com.company;

public class Prc_no_of_arguments {
    public static void main(String[] args) {
        int c = varargs(2, 4, 6, 8);
        System.out.println("Result : " + c);
    }

    static int varargs(int ...arr){
        int res = 0;
        for(int element : arr){
            res = res + element;
        }
        res = res/arr.length;
        return res;
    }
}
