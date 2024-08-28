from flask import Flask

app = Flask(__name__)


def make_bold(function):
    def wrapper_function():
        return f"<b>{function()}</b>"
    return wrapper_function


@app.route('/')
def hello_world():
    return '<h1 style="text-align: center">Hello, World</h1>' \
           '<img src="https://media.istockphoto.com/id/1371547852/photo/hello-and-welcome-written-white-lightbox' \
           '-sitting-on-blue-background.jpg?s=612x612&w=0&k=20&c=yHoWPj8ku6gylmAngW2QSgHY-gNaaO5baG-ozYWZq1c=" ' \
           'width="400">'


@app.route('/<name>/<int:age>')
@make_bold
def print_name(name, age):
    return f"Hello my name is {name}. My age is {age} years old."


if __name__ == "__main__":
    app.run(debug=True)

