package com.company;

import java.util.ArrayList;
import java.util.List;

public class literals {
    public static void main(String[] args) {
        boolean bl = false;
        List<String> names = new ArrayList<>();
        int[] arr;
        names.add("Raman");
        names.add("Kumar");
        names.add("Manjhi");
        try {
            String a = names.get(2);
        } catch (Exception e) {
            e.printStackTrace();
        }
        String str = "The value of the boolean bl is : ";
        String message = "My phone number is : ";
        long phone = 6204239638L;
        System.out.print(str);
        System.out.println(bl);
        System.out.print(message);
        System.out.println(phone);

    }
}
