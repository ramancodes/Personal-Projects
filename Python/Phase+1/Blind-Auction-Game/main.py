from replit import clear
from art import logo
#HINT: You can call clear() to clear the output in the console.
stop = False
bidders = {}

def winner_check(bid_record):
    winner = ""
    winner_by = 0
    for names in bidders:
        if winner_by < bidders[names]:
            winner_by = bidders[names]
            winner = names
    print(f"The Winner is {winner} with a bid of Rs. {winner_by}.")

while not stop:
    print(logo)
    continue_check = ""
    name = input("What is your name? : ")
    for person in bidders:
        if person == name:
            print("The name already exists! Try to enter a differnt name.")
            continue_check = input("Type 'ok' to continue bidding or 'no' to end it.\n")
    
    if continue_check == 'ok':
        clear()
        continue
    elif continue_check == 'no':
        clear()
        break
    
    bid_price = int(input("What's your bid? : Rs. "))
    bidders[name] = bid_price
    choice = input("Are there any other bidders? Type 'yes' or 'no'\n").lower()
    if choice != "yes":
        stop = True
    clear()

winner_check(bidders)

choice = input("\nDo you want to see the report? Type 'yes' or 'no'.\n").lower()
if choice == "yes":
    print("\n")
    print(bidders)
else:
    print("\nThank You!")