import pandas as pd

data = pd.read_csv("nato_phonetic_alphabet.csv")
dict_data = {value.letter: value.code for (index, value) in data.iterrows()}


def generate_phonetic_code():
    word = input("Enter a word: ").upper()
    try:
        phonetic_code = [dict_data[letter] for letter in word]
    except KeyError:
        print("Sorry, only letters in alphabet please.")
        generate_phonetic_code()
    else:
        print(phonetic_code)


generate_phonetic_code()
