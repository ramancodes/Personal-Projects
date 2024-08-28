#Number Guessing Game Objectives:

# Include an ASCII art logo.
# Allow the player to submit a guess for a number between 1 and 100.
# Check user's guess against actual answer. Print "Too high." or "Too low." depending on the user's answer. 
# If they got the answer correct, show the actual answer to the player.
# Track the number of turns remaining.
# If they run out of turns, provide feedback to the player. 
# Include two different difficulty levels (e.g., 10 guesses in easy mode, only 5 guesses in hard mode).

from art import logo
import random
from replit import clear

def loading_part():
    """This prints the loading animation"""
    loading_times = random.randint(30, 50)
    print("\nLoading", end= " ")
    for _ in range(loading_times):
        print(".", end = "")

def compare(user, computer):
    """This compares the user guess with the computer choosen number"""
    if user>computer:
        return "    --> Too High 😒"
    elif computer>user:
        return "    --> Too low 😢"
    else:
        return "    --> You Won! 😍🎉"

def play_game(difficulty_level):
    """This accepts the difficulty level of the game and starts the game"""
    print(logo)
    print("Welcome to the number guessing game! 🎉")
    print("I am choosing a number between 1 to 100.")
    computer = random.randint(1, 100)
    if difficulty_level == "hard":
        no_of_times_allowed = 5
    else:
        no_of_times_allowed = 10
    print(f"You have got {no_of_times_allowed} chances to win the game. 😎\nCan you guess the number? 🤔\n")

    won_the_game = False
    for i in range(no_of_times_allowed, 0, -1):
        user = int(input("Enter the number: "))
        message = compare(user, computer)
        print(message)
        print(f"You have {i} attempts left.")
        if message == "You Won! 😍🎉":
            won_the_game = True
            break
    if not won_the_game:
        print("You Lose 😕! Try next time.")
    print(f"The number is {computer}.")
    input("\nPress Enter to continue...")
    
is_game_ended = False
while not is_game_ended:
    print(logo)
    difficulty_level = input("Choose a difficulty level. Type 'easy' or 'hard': ").lower()
    #loading animation
    loading_part()
    if difficulty_level != "hard" and difficulty_level != "easy":
        print("\nSorry Wrong Choice! Please try again.")
        input("\nPress Enter to continue...")
    else:
        input("\nPress Enter to continue...")
        clear()
        play_game(difficulty_level)
    clear()
    play_more_game = input("Do you want to play one more game? Type 'y' or 'n': ").lower()
    if play_more_game != 'y':
        is_game_ended = True
    clear()