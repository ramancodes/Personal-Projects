import json
import requests
import model_class_prc

url = 'https://newsapi.org/v2/everything?q=apple&from=2022-12-30&to=2022-12-30&sortBy=popularity&apiKey=827f6eb5908d42a2b0cc8b5155faeb08'

data = requests.get(url=url)


# parsed_data_0 = data.text.split("\n")
# parsed_data_1 = [d.split(",") for d in parsed_data_0]
# data_names = ['sepal length', 'sepal width', 'petal length', 'petal width', 'class']

result = model_class_prc.iris_from_dict(json.loads(data.text))

print(result)