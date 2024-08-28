#Password Generator Project
import random
letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

print("Welcome to the PyPassword Generator!")
nr_letters= int(input("How many letters would you like in your password?\n")) 
nr_symbols = int(input(f"How many symbols would you like?\n"))
nr_numbers = int(input(f"How many numbers would you like?\n"))

#Eazy Level - Order not randomised:
#e.g. 4 letter, 2 symbol, 2 number = JduE&!91


#Hard Level - Order of characters randomised:
#e.g. 4 letter, 2 symbol, 2 number = g^2jk8&P

#easy level -->
'''
password = ""

for i in range(0, nr_letters):
  select = random.randint(0, len(letters)-1)
  password += letters[select]

for i in range(0, nr_symbols):
  select = random.randint(0, len(symbols)-1)
  password += symbols[select]

for i in range(0, nr_numbers):
  select = random.randint(0, len(numbers)-1)
  password += numbers[select]

print("Your Password is : " + password)
'''

#hard level 0 -->
'''
password = ""
pass_reference = [letters, numbers, symbols]
total_char = nr_letters + nr_numbers + nr_symbols
l = nr_letters
n = nr_numbers
s = nr_symbols

while len(password) != total_char:
  select_type =  random.randint(0, 2)
  
  if select_type == 0 and l > 0:
    select_char = random.randint(0, len(letters)-1)
    password += pass_reference[select_type][select_char]
    l -= 1
    
  elif select_type == 1 and n > 0:
    select_char = random.randint(0, len(numbers)-1)
    password += pass_reference[select_type][select_char]
    n -= 1
    
  elif select_type == 2 and s > 0:
    select_char = random.randint(0, len(symbols)-1)
    password += pass_reference[select_type][select_char]
    s -= 1
    
print(password)
'''

#hard level 1-->

password_list = []

for i in range(0, nr_letters):
  password_list.append(random.choice(letters))

for i in range(0, nr_symbols):
  password_list.append(random.choice(symbols))

for i in range(0, nr_numbers):
  password_list.append(random.choice(numbers))

random.shuffle(password_list)

password = ""
for i in password_list:
  password += i

print("Your password is : "+password)