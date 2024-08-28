import requests
from datetime import datetime
from dateutil.tz import tzlocal

lat = 28.613939
lng = 77.209023

parameters = {
    "lat": lat,
    "lng": lng,
    "formatted": 0,
}
response = requests.get(url="https://api.sunrise-sunset.org/json", params=parameters)
sunrise_utc = response.json()["results"]["sunrise"]



print(sunrise_utc)
