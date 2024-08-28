from flask import Flask, render_template
from datetime import datetime
import requests

app = Flask(__name__)
url = "https://api.npoint.io/c790b4d5cab58020d391"


# homepage
@app.route('/')
def home():
    footer = [datetime.now().year, "Raman"]
    return render_template("index.html", footer=footer)


# blog page
@app.route('/blog')
def blog():
    footer = [datetime.now().year, "Raman"]
    response = requests.get(url=url)
    data = response.json()
    return render_template("blog.html", footer=footer, data=data)


if __name__ == "__main__":
    app.run(debug=True)

