from tkinter import *


def button_clicked():
    my_label.config(text=input_data.get())


window = Tk()
window.title("This is my Window")
window.minsize(width=500, height=300)

my_label = Label(text="This will change")
my_label.pack()

input_data = Entry(width=10)
input_data.pack()

button = Button(text="Click here")
button.pack()
button.config(command=button_clicked)


window.mainloop()