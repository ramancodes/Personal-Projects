from flask import Flask, render_template
import requests
from post import Post

app = Flask(__name__)
url = "https://newsapi.org/v2/top-headlines?sources=techcrunch&apiKey=48ddd73b41004521b42db13f24b5ffd9"
posts = []


@app.route('/')
def home():
    posts.clear()
    response = requests.get(url=url)
    data = response.json()["articles"]
    index = 0
    for article in data:
        posts.append(Post(
            post_id=index,
            title=article["title"],
            subtitle=article["description"],
            author=article["author"],
            body=article["content"],
            post_url=article["url"],
            image_url=article["urlToImage"],
            date=article["publishedAt"]
        ))
        index += 1
    return render_template("index.html", posts=posts)


@app.route('/post/<int:index>')
def post(index):
    current_post = None
    for data in posts:
        if data.id == index:
            current_post = data
    return render_template("post.html", post=current_post)


if __name__ == "__main__":
    app.run(debug=True)
