package CWH_Projects;
import java.util.*;

class Game{
    private int compRandom;
    private int userInput;
    static int noOfGuesses = 0;

    //constructor for random number
    Game(){
        Random rd = new Random();
        compRandom = rd.nextInt(1, 100);
        System.out.println("Ready....");
    }

    //method to take input
    public void takeInputUser(){
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter the number : ");
        userInput = sc.nextInt();
        noOfGuesses++;
    }

    public int getCompRandom(){
        return compRandom;
    }

    public int getUserInput(){
        return userInput;
    }

    public static int getNoOfGuesses(){
        return noOfGuesses;
    }

    //check if the no is correct
    boolean isCorrectNo(){
        if(getCompRandom()==getUserInput()){
            return true;
        } else {
            return false;
        }
    }

    //correct or not result print
    public void check(){
        if(isCorrectNo()){
            System.out.println("Your guessed the right number");
            System.out.println("Total no of guesses is " + getNoOfGuesses());
        }else {
            notCorrect();
        }
    }

    //method if not correct
    void notCorrect(){
        if(getUserInput()>getCompRandom()){
            System.out.println("The number entered is higher");
            System.out.println("No of guesses : " + getNoOfGuesses());
        }
        else {
            System.out.println("The number entered is lower");
            System.out.println("No of guesses : " + getNoOfGuesses());
        }
       }
}

public class Random_no_guess_game {
    public static void main(String[] args) {
        System.out.println("Welcome to the guess the number game");

        Game start = new Game();
        do{
            start.takeInputUser();
            start.check();
        }while (!start.isCorrectNo());

    }

}