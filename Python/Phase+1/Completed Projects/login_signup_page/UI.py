from tkinter import *
from tkinter import messagebox
from database import MongoDB


# login_signup_homepage
class LoginSignUp:
    def __init__(self):
        self.window = Tk()
        self.window.title("Login Sign Up Page")

        # canvas
        self.canvas = Canvas(width=480, height=671)
        self.canvas.grid(row=0, column=0, columnspan=2)
        bg_image = PhotoImage(file="images/bg.png")
        self.canvas.create_image(240, 335, image=bg_image)

        self.canvas.create_text(240, 200, text="Login / SignUp", fill="white",
                                font=("Ariel", 40, "bold"))

        # button
        login = PhotoImage(file="images/login.png")
        signup = PhotoImage(file="images/signup.png")
        self.loginButton = Button(
            image=login,
            command=self.call_login,
            highlightthickness=0,
            width=80,
            height=30)
        self.SignUpButton = Button(
            image=signup,
            command=self.call_signup,
            highlightthickness=0,
            width=80,
            height=32)
        self.loginButton.grid(row=0, column=0)
        self.SignUpButton.grid(row=0, column=1)

        self.window.mainloop()

    def call_login(self):
        self.window.destroy()
        Login()

    def call_signup(self):
        self.window.destroy()
        SignUp()


# login_page
class Login:
    def __init__(self):
        self.window = Tk()
        self.window.title("Login Page")

        # canvas
        self.canvas = Canvas(width=480, height=671)
        self.canvas.grid(row=0, column=0, columnspan=4, rowspan=10)
        bg_image = PhotoImage(file="images/bg.png")
        self.canvas.create_image(240, 335, image=bg_image)

        self.canvas.create_text(240, 100, text="Login Here", fill="white",
                                font=("Ariel", 40, "bold"))

        # labels
        self.email_label = Label(text="Email:", font=("Ariel", 15), background="#9c2fb9", fg="white")
        self.password_label = Label(text="Password:", font=("Ariel", 15), background="#9c2fb9", fg="white")
        self.email_label.grid(row=3, column=0)
        self.password_label.grid(row=4, column=0)

        # entry
        self.email_entry = Entry(width=40)
        self.password_entry = Entry(width=40, textvariable=StringVar(), show="*")
        self.email_entry.focus()
        self.email_entry.grid(row=3, column=1, columnspan=2)
        self.password_entry.grid(row=4, column=1, columnspan=2)

        # button
        submit = PhotoImage(file="images/submit.png")
        back = PhotoImage(file="images/back.png")
        self.submit_button = Button(
            image=submit,
            command=self.get_login_creds,
            width=80,
            height=40,
            highlightthickness=0)
        self.back_button = Button(
            image=back,
            highlightthickness=0,
            command=self.go_back
        )
        self.submit_button.grid(row=5, column=1)
        self.back_button.grid(row=6, column=1)

        self.window.mainloop()

    def get_login_creds(self):
        email = self.email_entry.get()
        password = self.password_entry.get()

        save_db = MongoDB(email=email, password=password, db="users_db", collection="users")
        result = save_db.login()
        messagebox.showinfo(title="Result", message=result)

    def go_back(self):
        self.window.destroy()
        LoginSignUp()

    def show_pass(self):
        password = self.password_entry.get()
        messagebox.showinfo(title="Password", message=f"Your password is: \n{password}")


# sign_up_page
class SignUp:
    def __init__(self):
        self.window = Tk()
        self.window.title("Sign Up Page")

        # canvas
        self.canvas = Canvas(width=480, height=671)
        self.canvas.grid(row=0, column=0, columnspan=4, rowspan=10)
        bg_image = PhotoImage(file="images/bg.png")
        self.canvas.create_image(240, 335, image=bg_image)

        self.canvas.create_text(240, 100, text="Sign Up Here", fill="white",
                                font=("Ariel", 40, "bold"))

        # labels
        self.name_label = Label(text="Name:", font=("Ariel", 15), background="#9c2fb9", fg="white")
        self.email_label = Label(text="Email:", font=("Ariel", 15), background="#9c2fb9", fg="white")
        self.password_label = Label(text="Password:", font=("Ariel", 15), background="#9c2fb9", fg="white")
        self.name_label.grid(row=3, column=0)
        self.email_label.grid(row=4, column=0)
        self.password_label.grid(row=5, column=0)

        # entry
        self.name_entry = Entry(width=40)
        self.email_entry = Entry(width=40)
        self.password_entry = Entry(width=40, textvariable=StringVar(), show="*")
        self.name_entry.focus()
        self.name_entry.grid(row=3, column=1, columnspan=2)
        self.email_entry.grid(row=4, column=1, columnspan=2)
        self.password_entry.grid(row=5, column=1, columnspan=2)

        # button
        submit = PhotoImage(file="images/submit.png")
        back = PhotoImage(file="images/back.png")
        self.submit_button = Button(image=submit,
                                    command=self.get_signup_creds,
                                    width=80,
                                    height=40,
                                    highlightthickness=0)
        self.back_button = Button(
            image=back,
            highlightthickness=0,
            command=self.go_back
        )
        self.submit_button.grid(row=6, column=1)
        self.back_button.grid(row=7, column=1)

        self.window.mainloop()

    def get_signup_creds(self):
        name = self.name_entry.get()
        email = self.email_entry.get()
        password = self.password_entry.get()

        save_db = MongoDB(email=email, password=password, name=name, db="users_db", collection="users")
        result = save_db.signup()
        messagebox.showinfo(title="Result", message=result)

    def go_back(self):
        self.window.destroy()
        LoginSignUp()

    def show_pass(self):
        password = self.password_entry.get()
        messagebox.showinfo(title="Password", message=f"Your password is: \n{password}")
