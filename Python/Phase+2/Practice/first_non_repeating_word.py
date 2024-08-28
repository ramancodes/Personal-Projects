def first_non_repeating_character(string):
    count = {} #python dictionary to store count of characters
    string = string.lower().replace(" ", "")

    #count the characters in the string
    for character in string:
        if character not in count.keys():
            count[character] = 1
        else:
            count[character] += 1
    
    print("Count of the Characters: ")
    print(count)
    
    #return the first non-repeating character
    for key, value in count.items():
        if value == 1:
            return key
    else:
        return False

#string input and display result
character = first_non_repeating_character(input("Enter a string: "))
if character!=False:
    print("First Non-repeating Character:",character)
else:
    print('No Non-Repeating Character Found!')
