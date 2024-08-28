import random

rock = '''
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
'''

paper = '''
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
'''

scissors = '''
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
'''

#Write your code below this line 👇

print("Welcome To Rock Paper Scissors Game.")
game_images = [rock, paper, scissors]
options = ["rock", "paper", "scissors"] #rock -0 , paper - 1, scissors - 2

#user_part
user_choice = input("What do you want to choose? Type 'Rock', 'Paper' or 'Scissors'\n").lower()
try:
  user_index = options.index(user_choice)
except:
  print("Invalid Entry")
  exit()
  

#computer_part
computer_choice = random.choice(options)
result = ""
computer_index = options.index(computer_choice)

#descision part
if computer_index == 0 and user_index == 2:
  result = "You lose!"
elif computer_index > user_index:
  result = "You lose!"
elif user_index == 0 and computer_index == 2:
  result = "You win!"
elif user_index > computer_index and user_index < 3:
  result = "You win!"

print("You : "+ user_choice)
print(game_images[user_index])
print("Computer : "+ computer_choice)
print(game_images[computer_index])
print(result)