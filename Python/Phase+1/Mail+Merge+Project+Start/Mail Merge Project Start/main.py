PLACEHOLDER = '[name]'

with open("./Input/Names/invited_names.txt") as names_file:
    names = names_file.readlines()

with open("./Input/Letters/starting_letter.txt") as letter_file:
    letter_contents = letter_file.read()

for name in names:
    new_name = name.strip()
    new_letter_contents = letter_contents.replace(PLACEHOLDER, new_name)
    with open(f"./Output/ReadyToSend/letter_for_{new_name}.txt", mode="w") as invite:
        invite.write(new_letter_contents)


