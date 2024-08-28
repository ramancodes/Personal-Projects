class Employee:
    def __init__(self, name, salary):
        self.name = name
        self.salary = salary

    def print_details(self):
        return f"{self.name} earns {self.salary} per month."

    def __add__(self, other):
        return self.salary + other.salary

    def __sub__(self, other):
        return self.salary-other.salary

    def __repr__(self):
        return f"Employee('{self.name}', {self.salary})"

    def __str__(self):
        return self.print_details()


rahul = Employee("Rahul", 366)
kamlesh = Employee("Kamlesh", 255)
print(rahul+kamlesh)
print(rahul-kamlesh)
print(rahul)
print(repr(kamlesh)) 