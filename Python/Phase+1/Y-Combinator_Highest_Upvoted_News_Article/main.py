from bs4 import BeautifulSoup
import requests
import pandas as pd

response = requests.get("https://news.ycombinator.com/")
webpage = response.text

soup = BeautifulSoup(webpage, "html.parser")

# names of all the articles
articles = soup.find_all(name="span", class_="titleline")

# list of all the names
article_names = [article.getText() for article in articles]

# upvote scores of the articles
article_scores = soup.find_all(name="span", class_="score")

# list of the upvote scores of the articles
scores = [int(score.getText().split()[0]) for score in article_scores]

# highest upvoted article
highest_upvote = max(scores)
index_highest = scores.index(highest_upvote)

print("Highest Upvoted Article:")
print(f"Article Name: {article_names[index_highest]}\nArticle Upvote: {scores[index_highest]}")

# creating a data frame
data = {
    "Article Name": article_names,
    "Upvotes": scores,
}
df = pd.DataFrame(data)

#  exporting to a csv file
df.to_csv("Articles.csv")
