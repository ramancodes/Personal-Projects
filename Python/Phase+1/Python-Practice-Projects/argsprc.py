# def argfunc(*args):
#     print(type(args))
#     print(args)
#     for i in args:
#         print(i)

def kwargfunc(**kwargs):
    print(type(kwargs))
    print(kwargs)
    for key, value in kwargs.items():
        print(f"{key} is for {value}")

# l = ["Hello", "hii", "namaste", "ne ha"]
# argfunc("Hello", "hii", "namaste", "ne ha")
# argfunc(*l)
dic = {"Home":"live", "Tution":"Study", "School":"study", "office":"job"}
kwargfunc(**dic)