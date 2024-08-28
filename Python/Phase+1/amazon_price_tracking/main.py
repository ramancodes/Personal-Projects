from bs4 import BeautifulSoup
import requests

# checking quantities
lowest_expected_price = 20
url = "https://www.amazon.com/Hey-Dude-Wally-Stretch-Loafers-Black-11/dp/B00TS72QLC/ref=sr_1_6?qid=1677217683&s=fashion-mens-intl-ship&sr=1-6"

# getting response from the amazon website
headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) "
                  "Chrome/110.0.0.0 Safari/537.36 Edg/110.0.1587.50",
    "Accept-Language": "en-US,en;q=0.9",
}
response = requests.get(url=url, headers=headers)
soup = BeautifulSoup(response.text, "lxml")

# getting the current price of the product
result = soup.find_all(name="span", class_="a-offscreen")
count = 0
for r in result:
    if "$" in r.getText():
        count = count+1
current_price = [float(price.getText()[1:]) for price in result[:count]]

# getting the product name
name = soup.find(name="span", class_="a-size-large product-title-word-break", id="productTitle")
product_name = name.getText().strip()

# checking the product price
# print(f"Product name: {product_name}\nProduct Price: {current_price}")
if len(current_price) == 1:
    if current_price[0] < lowest_expected_price:
        print(f'The price of "{product_name}" has reached below ${lowest_expected_price}. You can buy it now.')
    else:
        print(f"The price is still higher than ${lowest_expected_price}. The current price is ${current_price[0]}.")
else:
    if current_price[0] < lowest_expected_price < current_price[1]:
        print(f'The price of "{product_name}" is between ${current_price[0]} and ${current_price[1]}. '
              f'You can buy it now.')
    elif current_price[0] < lowest_expected_price:
        print(f'The price of "{product_name}" has reached below ${lowest_expected_price}. You can buy it now.')
    else:
        print(f"The price is still higher than ${lowest_expected_price}. "
              f"The current price is ${current_price[0]}-${current_price[1]}")

