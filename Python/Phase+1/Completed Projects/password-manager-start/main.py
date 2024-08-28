from json import JSONDecodeError
from random import choice, randint, shuffle
from tkinter import *
from tkinter import messagebox
import pyperclip
from datetime import datetime
import json

# ---------------------------- CONSTANTS ------------------------------- #
letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
           'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
           'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']


# ---------------------------- SEARCH ------------------------------- #
def search():
    website = website_entry.get().lower()
    try:
        with open("Passwords.json", "r") as data_file:
            data = json.load(data_file)
    except FileNotFoundError:
        messagebox.showinfo(title="Warning!", message="No Data Available in the Record.")
    else:
        if website in data:
            email = data[website]['email']
            password = data[website]['password']
            messagebox.showinfo(title=website.title(), message=f"Email: {email} "
                                                               f"\nPassword: {password} "
                                                               f"\n\nYour password is copied to clipboard.")
            pyperclip.copy(password)
        else:
            messagebox.showinfo(title="Warning!", message=f"No Details for {website.title()} exists.")


# ---------------------------- PASSWORD GENERATOR ------------------------------- #
def password_generator():
    password_entry.delete(0, END)
    nr_letters = randint(6, 10)
    nr_symbols = randint(1, (12 - nr_letters))
    numbers_end = 14 - (nr_letters + nr_symbols)
    if numbers_end == 0:
        numbers_end = 1
    nr_numbers = randint(1, numbers_end)

    password_letters = [choice(letters) for _ in range(0, nr_letters)]
    password_symbols = [choice(symbols) for _ in range(0, nr_symbols)]
    password_numbers = [choice(numbers) for _ in range(0, nr_numbers)]

    password_list = password_letters + password_symbols + password_numbers
    shuffle(password_list)

    password = "".join(password_list)
    pyperclip.copy(password)

    password_entry.insert(0, password)


# ---------------------------- SAVE PASSWORD ------------------------------- #
def save_password():
    website = website_entry.get().lower()
    email = email_username_entry.get().lower()
    password = password_entry.get().lower()
    new_data = {
        website: {
            "email": email,
            "password": password,
        }
    }

    if len(website) == 0 or len(email) == 0 or len(password) == 0:
        messagebox.showinfo(title="Warning!", message="Don't leave any of the field empty.")
    else:
        is_ok = messagebox.askokcancel(title="Confirmation", message=f"The details entered are: "
                                                                     f"\n\nWebsite: {website} "
                                                                     f"\nEmail: {email} "
                                                                     f"\nPassword: {password} "
                                                                     f"\n\nIs it ok to save?")

        if is_ok:
            try:
                with open("Passwords.json", mode="r") as data_file:
                    # reading old data from json file
                    data = json.load(data_file)
            except FileNotFoundError:
                with open("Passwords.json", mode="w") as data_file:
                    # creating a new json file
                    json.dump(new_data, data_file, indent=4)
            except JSONDecodeError:
                with open("Passwords.json", mode="w") as data_file:
                    # creating a new json file
                    json.dump(new_data, data_file, indent=4)
            else:
                # update the new data
                data.update(new_data)
                with open("Passwords.json", mode="w") as data_file:
                    # saving the updated data to the json file
                    json.dump(data, data_file, indent=4)
            finally:
                website_entry.delete(0, END)
                password_entry.delete(0, END)
                email_username_entry.delete(0, END)

            with open("log.txt", "a") as log_file:
                log_file.write(f"New Record of {website.title()} Added at {datetime.now()}\n")


# ---------------------------- UI SETUP ------------------------------- #
# window
window = Tk()
window.title("Password Manager")
window.config(padx=50, pady=50)

# canvas
canvas = Canvas(width=150, height=200)
img = PhotoImage(file="logo.png")
canvas.create_image(90, 100, image=img)
canvas.grid(column=1, row=0)

# label
website_label = Label(text="Website:")
website_label.grid(column=0, row=1)
email_username_label = Label(text="Email/Username:")
email_username_label.grid(column=0, row=2)
password_label = Label(text="Password:")
password_label.grid(column=0, row=3)

# button
generate_password_button = Button(text="Generate Password", command=password_generator)
generate_password_button.grid(column=2, row=3)
add_button = Button(text="Add / Update", width=36, command=save_password)
add_button.grid(column=1, row=4, columnspan=2)
search_button = Button(text="Search", width=13, command=search)
search_button.grid(column=2, row=1)

# entry
website_entry = Entry(width=23)
website_entry.focus()
website_entry.grid(column=1, row=1, padx=5, pady=5)
email_username_entry = Entry(width=42)
email_username_entry.insert(0, "youremail@email.com")
email_username_entry.grid(column=1, row=2, columnspan=2, padx=5, pady=5)
password_entry = Entry(width=23)
password_entry.grid(column=1, row=3, padx=5, pady=5)

window.mainloop()
