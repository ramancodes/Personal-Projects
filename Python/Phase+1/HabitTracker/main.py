import requests
from datetime import datetime

USERNAME = "ramancodes"
TOKEN = "raman8709405374"
GRAPHID = "graph1"
TODAY = datetime.today().strftime("%Y%m%d")
SCORE = "12.5"
headers = {
    "X-USER-TOKEN": TOKEN,
}


# creating an account
pixela_endpoints = "https://pixe.la/v1/users"
user_params = {
    "token": TOKEN,
    "username": USERNAME,
    "agreeTermsOfService": "yes",
    "notMinor": "yes",
}
# response = requests.post(url=pixela_endpoints, json=user_params)
# print(response.text)


# creating a graph
graph_endpoint = f"{pixela_endpoints}/{USERNAME}/graphs"
graph_config = {
    "id": GRAPHID,
    "name": "Coding Graph",
    "unit": "hours",
    "type": "float",
    "color": "kuro",
}
# response = requests.post(url=graph_endpoint, json=graph_config, headers=headers)
# print(response.text)


# plotting a point
post_pixel_endpoints = f"{pixela_endpoints}/{USERNAME}/graphs/{GRAPHID}"
pixel_params = {
    "date": TODAY,
    "quantity": SCORE,
}
# response = requests.post(url=post_pixel_endpoints, json=pixel_params, headers=headers)
# print(response.text)


# updating a pixel data
update_pixel_endpoint = f"{pixela_endpoints}/{USERNAME}/graphs/{GRAPHID}/{TODAY}"
update_pixel_params = {
    "quantity": SCORE,
}
# response = requests.put(url=update_pixel_endpoint, json=update_pixel_params, headers=headers)
# print(response.text)


# delete a pixel
delete_a_pixel = f"{pixela_endpoints}/{USERNAME}/graphs/{GRAPHID}/{TODAY}"
# response = requests.delete(url=delete_a_pixel, headers=headers)
# print(response.text)

