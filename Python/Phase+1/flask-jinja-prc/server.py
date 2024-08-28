from flask import Flask, render_template
import random
from datetime import datetime
import requests

app = Flask(__name__)
url = ["https://api.genderize.io", "https://api.agify.io"]


# homepage
@app.route('/')
def home():
    footer = [datetime.now().year, "Raman Kumar Manjhi"]
    random_number = random.randint(0, 9)
    return render_template("index.html", num=random_number, footer=footer)


# age & gender guess game page
@app.route('/<name>')
def guess(name):
    footer = [datetime.now().year, "Raman Kumar Manjhi"]
    parameters = {
        "name": name,
    }
    response = [requests.get(url=url[0], params=parameters), requests.get(url=url[1], params=parameters)]
    data = [response[0].json(), response[1].json()]
    result = [data[0]["name"], data[0]["gender"], data[1]["age"]]
    return render_template("guess.html", footer=footer, result=result)


if __name__ == "__main__":
    app.run(debug=True)

