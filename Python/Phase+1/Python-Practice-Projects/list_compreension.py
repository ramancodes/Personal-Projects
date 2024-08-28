names = ["Raman", "Sneha", "Akash", "Riya", "Choti"]
numbers = [1, 2, 3, 4, 5]
ls = [name.upper()+str(n) for name in names if len(name)<5 for n in numbers]
print(ls)
