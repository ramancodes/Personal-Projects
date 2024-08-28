package Package2;

import java.util.Scanner;

public class Prc_Conditional_3_website_url {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter your Website");
        String web = scanner.nextLine();
        String separator = ".";
        int charNo = web.lastIndexOf(separator);
        String domain = web.substring(charNo);

        switch (domain) {
            case ".com" -> System.out.println("Your website is a commercial business website");
            case ".org" -> System.out.println("Your website is a organization website");
            case ".gov" -> System.out.println("Your website is a government agency website");
            case ".edu" -> System.out.println("Your website is educational institution website");
            case ".net" -> System.out.println("Your website is a network organization website");
            case ".mil" -> System.out.println("Your website is a military website");
            default -> System.out.println("This domain is not registered with this program");
        }
    }
}
