def printing_stars(manglik):
    if manglik:
        for x in range(1, no_of_stars+1):
            for _ in range(1, x+1):
                print("*", end = "")
            print("")
    else:
        for x in range(no_of_stars, 0, -1):
            for _ in range(x, 0, -1):
                print("*", end = "")
            print("")

no_of_stars = int(input("Enter the number of stars: "))
mangal = input("Are you a manglik? Type 'y' or 'n': ")
manglik = False

if mangal == 'y':
    manglik = True

printing_stars(manglik)