with open("file1.txt") as f:
    ls1 = f.readlines()

with open("file2.txt") as f:
    ls2 = f.readlines()

result = [int(x) for x in ls1 if x in ls2]
# Write your code above 👆
print(result)