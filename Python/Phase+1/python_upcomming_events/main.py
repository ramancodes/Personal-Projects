from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from webdriver_manager.chrome import ChromeDriverManager

driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()))
driver.get("https://www.python.org/")

event_dates = driver.find_elements(By.CSS_SELECTOR, "div.event-widget time")
dates = [event.text for event in event_dates]

event_names = driver.find_elements(By.CSS_SELECTOR, "div.event-widget li a")
names = [event.text for event in event_names]

# python_events = dict(zip(names, dates))
python_events = {}

for n in range(len(dates)):
    python_events[n] = {
        "name": names[n],
        "date": dates[n],
    }

print(python_events)

