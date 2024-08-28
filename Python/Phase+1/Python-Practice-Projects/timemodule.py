import time

class Hello:
    def __init__(self):
        self.time = time.asctime(time.localtime(time.time()))

    def display_time(self):
        """this function tells the user current time and date"""
        return f"Today is {self.time}."

    @classmethod
    def greet_the_user(cls, name):
        """this function greets the user"""
        t = time.localtime()
        hour = t.tm_hour
        cls.name = name
        if hour == 12:
            return f"Good Noon, {cls.name}."
        elif hour < 12:
            return f"Good Morning, {cls.name}."
        elif hour > 12 and hour < 16:
            return f"Good Afternoon, {cls.name}."
        elif hour >= 16 and hour < 20:
            return f"Good Evening, {cls.name}."
        else:
            return f"Good Night, {cls.name}."

#Current Time and Date

user1 = Hello()
print(user1.display_time())

#Greet The User

print(Hello.greet_the_user("Sneha"))