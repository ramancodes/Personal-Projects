from tkinter import *
import pandas as pd
from random import choice

# ------------------------Getting The words from CSV-----------------------
current_card = {}
all_words = {}

try:
    data = pd.read_csv("data/words_to_learn.csv")
except FileNotFoundError:
    original_data = pd.read_csv("data/french_words.csv")
    all_words = original_data.to_dict(orient="records")
else:
    all_words = data.to_dict(orient="records")


def next_card():
    global current_card, flip_timer
    window.after_cancel(flip_timer)
    current_card = choice(all_words)
    french_word = current_card['French']
    canvas.itemconfig(card_word, text=french_word, fill="black")
    canvas.itemconfig(card_title, text="French", fill="black")
    canvas.itemconfig(card_img, image=card_front_img)
    flip_timer = window.after(3000, func=flip_card)


def is_known():
    global current_card, all_words
    all_words.remove(current_card)
    new_data = pd.DataFrame(all_words)
    new_data.to_csv("data/words_to_learn.csv", index=False)
    next_card()


def flip_card():
    canvas.itemconfig(card_img, image=card_back_img)
    english_word = current_card['English']
    canvas.itemconfig(card_word, text=english_word, fill="White")
    canvas.itemconfig(card_title, text="English", fill="white")


# ------------------------------UI----------------------------------------
BACKGROUND_COLOR = "#B1DDC6"

# main_window
window = Tk()
window.title("Flash Card Game")
window.config(padx=50, pady=50, bg=BACKGROUND_COLOR)

# flip_card_timer
flip_timer = window.after(3000, func=flip_card)

# card_canvas
canvas = Canvas(width=800, height=526)
card_front_img = PhotoImage(file="images/card_front.png")
card_back_img = PhotoImage(file="images/card_back.png")
card_img = canvas.create_image(400, 263, image=card_front_img)
canvas.config(bg=BACKGROUND_COLOR, highlightthickness=0)
card_title = canvas.create_text(400, 100, text="Title", font=("Ariel", 40, "italic"))
card_word = canvas.create_text(400, 263, text="word", font=("Ariel", 60, "bold"))
canvas.grid(row=0, column=0, columnspan=2)

# buttons
cross_img = PhotoImage(file="images/wrong.png")
unknown_button = Button(image=cross_img)
unknown_button.config(bg=BACKGROUND_COLOR, highlightthickness=0, command=next_card)
unknown_button.grid(row=1, column=0)

check_img = PhotoImage(file="images/right.png")
known_button = Button(image=check_img)
known_button.config(bg=BACKGROUND_COLOR, highlightthickness=0, command=is_known)
known_button.grid(row=1, column=1)

next_card()

window.mainloop()
