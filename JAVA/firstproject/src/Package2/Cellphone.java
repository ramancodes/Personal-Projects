package Package2;

import java.util.Scanner;

public class Cellphone {
    public static void main(String[] args) {
        Actions sam = new Actions();
        Scanner sc = new Scanner(System.in);

        System.out.print("Volume - ");
        int ch = sc.nextInt();

        switch (ch){
            case 1:
                sam.Ring();
                break;
            case 2:
                sam.Vibrate();
                break;
            case 3:
                sam.Silent();
                break;
            default:
                System.out.println("Invalid Entry!");
        }
    }
}

class Actions{
    public void Ring(){
        System.out.println("ringing............");
    }public void Vibrate(){
        System.out.println("vibrating............");
    }public void Silent(){
        System.out.println("beep............");
    }
}
