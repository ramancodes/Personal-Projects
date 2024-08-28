package Package2;

import java.util.Arrays;

public class Prc_Array_1 {
    public static void main(String[] args) {
        int[] arr = new int[]{2, 3, 4, 5, 7, 8, 9};
//        check an element in an array code
//        for (int a : arr) {
//            if (a == 4) {
//                System.out.println("True");
//            }
//            }

        //to find the max and min
        System.out.println(Arrays.stream(arr).min());

        //to printn array on reverse order
//        for (int i = arr.length-1; i>=0; i--){
//            System.out.println(arr[i]);
//        }
    }
}
