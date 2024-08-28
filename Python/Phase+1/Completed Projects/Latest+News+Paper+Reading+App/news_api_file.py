import json
import requests

data = {}
current_index = 0
url = 'https://newsapi.org/v2/everything?q=apple&from=2022-12-30&to=2022-12-30&sortBy=popularity&apiKey=827f6eb5908d42a2b0cc8b5155faeb08'
response = requests.get(url=url)
parsed_data = json.loads(response.text)
data = parsed_data["articles"]


def current_news_title():
    global current_index
    return data[current_index]['title']


def current_news_description():
    return data[current_index]['description']


def current_news_load_more_url():
    return data[current_index]['url']


def index_increment():
    global current_index
    if current_index == len(data):
        return -1
    else:
        current_index += 1


def index_decrement():
    global current_index
    if current_index == 0:
        return -1
    else:
        current_index -= 1
