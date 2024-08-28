/*
Not learnt custom exception properly
 */

package Package2;

import java.util.Scanner;

class RejectedNumberException extends Exception{
    @Override
    public String toString() {
        return super.toString() + "The input is invalid";
    }

    @Override
    public String getMessage() {
        return "Please enter the correct input";
    }
}

public class Prc_Custom_Exception {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number : ");
        int enteredNumber = Integer.parseInt(scanner.nextLine());


            try{
                if(enteredNumber!=4&&enteredNumber!=8) {
                    System.out.println("Your No is correct");
                }
//                throw new RejectedNumberException();
            }catch (Exception e){
                System.out.println(e.getMessage());
            }
    }

}
