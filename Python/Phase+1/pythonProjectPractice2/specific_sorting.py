import numpy as np


def biggest_number(numb):
    number = np.asarray(numb)
    for i in range(len(number)-1):

        if number[i] > 9:
            first_digit = number[i] / 10
        else:
            first_digit = number[i]

        if number[i + 1] > 10:
            next_first_digit = number[i] / 10
        else:
            next_first_digit = number[i]

        if next_first_digit < first_digit:
            number[i], number[i + 1] = number[i + 1], number[i]

    return number


num = list(map(int, input().split(" ")))


res = biggest_number(num)


for n in res:
    print(n, end="")

