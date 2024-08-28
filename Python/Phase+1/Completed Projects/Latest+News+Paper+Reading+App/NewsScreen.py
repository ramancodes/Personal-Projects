from tkinter import *
from tkinter import messagebox
import time
from news_api_file import *

# ---------------------------- UI SETUP ------------------------------- #
BACKGROUND_COLOR = "#B1DDC6"
t = time.localtime()
TIME = f"Date: {t.tm_yday} / {t.tm_mon} / {t.tm_year}"


def next_news():
    response_from_index = index_increment()
    if response_from_index == -1:
        messagebox.showinfo(title="Warning!", message="This is the last news for now!")
    else:
        get_news()


def prev_news():
    response_from_index = index_decrement()
    if response_from_index == -1:
        messagebox.showinfo(title="Warning!", message="This is the first news of today!")
    else:
        get_news()


def get_news():
    canvas.itemconfig(news_title, text=f"Title: {current_news_title()}")
    canvas.itemconfig(news_description, text=f"Description: {current_news_description()}")


def load_more():
    messagebox.showinfo(title="To Load more Click The Link Below",
                        message=f"Click on this link to read more: {current_news_load_more_url()}")


window = Tk()
window.title("News App")
canvas = Canvas(width=700, height=467)
background_img = PhotoImage(file="Images/background.png")
canvas.create_image(350, 233, image=background_img)
canvas.create_text(350, 50, text="Today's News", font=("Times New Roman", 40, "bold"), fill="white")
canvas.create_text(100, 120, text=TIME, fill="white", font=("Ariel", 15, 'bold'))
news_title = canvas.create_text(350, 200, text="Title : Title of The News", font=("Arial", 20, "bold"),
                                fill="white", width=600)
news_description = canvas.create_text(350, 300, text="Description: News Description",
                                      font=("Times New Roman", 15, "bold"), fill="white", width=600)
canvas.grid(row=0, column=0, columnspan=3)

# button
prev_button_img = PhotoImage(file="Images/prev_button.png")
next_button_img = PhotoImage(file="Images/next_button.png")
prev_button = Button(image=prev_button_img, command=prev_news)
next_button = Button(image=next_button_img, command=next_news)
read_more_button = Button(text="Read More", command=load_more)
read_more_button.grid(row=1, column=1)
prev_button.grid(row=2, column=0)
next_button.grid(row=2, column=2)
get_news()

window.mainloop()
