# method1
# import csv
# temp = []
# with open("weather_data.csv") as csv_file:
#     data = csv.reader(csv_file)
#     for i in data:
#         # if i[1] != 'temp':
#         temp.append(i[1])
# print(temp)
# new_temp = map(int, temp[1:])
# print(list(new_temp))

# method2
import pandas as pd
data = pd.read_csv("weather_data.csv")
# to print the complete table
# print(data)

# to print any single column
# weather_data = data['temp'].to_list()
# print(sum(weather_data)/len(weather_data))
# max_val = data['temp'].max()
# avg_data = data['temp'].mean()
# print(avg_data)
# print(max_val)
# print(data.temp)

# hottest_day = data[data.temp == data.temp.max()]
# hottest_days = data[data.condition == "Sunny"]
# print(hottest_days)

# day_condition = data[data.day == "Thursday"]
# cond = day_condition.condition
# print(day_condition)

# dict = {
#     'Names': ['Raman', 'Sneha', 'Akash'],
#     'Age': [21, 20, 25]
# }

# data = pd.DataFrame(dict)
# data.to_csv("ages.csv")