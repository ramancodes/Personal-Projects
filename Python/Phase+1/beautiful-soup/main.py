from bs4 import BeautifulSoup
import pandas as pd
with open("website1.html", encoding="utf-8") as file:
    contents = file.read()

soup = BeautifulSoup(contents, "html.parser")

# movies = soup.find(name="td", class_="titleColumn").find(name="a")
# print(movies.getText())

movies = soup.find_all(name="a", attrs={"title" : "value"})
for m in movies:
    print(m.get_text())

