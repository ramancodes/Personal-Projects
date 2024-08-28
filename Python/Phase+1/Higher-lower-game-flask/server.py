from flask import Flask
import random

app = Flask(__name__)
number = random.randint(0, 9)


@app.route('/')
def home_page():
    return '<h1>Guess a number between 0 and 9</h1>' \
           '<img src="https://media.giphy.com/media/' \
           'v1.Y2lkPTc5MGI3NjExNDg0YzUyNTA1YTNlNzExZjU1ZjAzMDVhZWYwZWNjMTgzNTdkMzRlMSZjdD1n/' \
           '3o7aCSPqXE5C6T8tBC/giphy.gif">'


@app.route('/<int:num>')
def check(num):
    if num > number:
        return '<h1>Too High, Try Again!</h1>' \
               '<img src="https://media.giphy.com/media/' \
               'v1.Y2lkPTc5MGI3NjExOTFlM2ZiMjcxYTk0NmI2MGUwYzcwOGY4YWYyZmQ3ZTE2Y2Y5YzIxNyZjdD1n/' \
               '3o6ZtaO9BZHcOjmErm/giphy.gif">'
    elif num < number:
        return '<h1>Too Low, Try Again!</h1>' \
               '<img src="https://media.giphy.com/media/' \
               'v1.Y2lkPTc5MGI3NjExZTM5YmUxMjM5ODYwOTY0YjU3Y2JkNTI0Y2ZlNjUzZTFmMDZhNjI5NiZjdD1n/' \
               'jD4DwBtqPXRXa/giphy-downsized-large.gif">'
    else:
        return '<h1>You Found Me!</h1>' \
               '<img src="https://media.giphy.com/media/' \
               'v1.Y2lkPTc5MGI3NjExMmFhNjA2ZWE1ODhhYmYyY2U4N2ZkODMyN2I2Y2JjNDdiNDdjZTY4OSZjdD1n/' \
               '4T7e4DmcrP9du/giphy.gif">'


if __name__ == "__main__":
    app.run(debug=False)
