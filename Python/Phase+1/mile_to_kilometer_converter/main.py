from tkinter import *

def calc():
    data_in_miles = entry.get()
    data_in_km = round(float(data_in_miles)*1.609, 2)
    result_label.config(text="{:.2f}".format(data_in_km))

window = Tk()
window.title("Mile to Kilometer Converter")
window.minsize(width=300, height=300)
window.config(padx=20, pady=20)

#label
distance_label = Label(text="Calculate The Distance", padx=10, pady=10, font=("Arial", 20, "bold"))
mile_label = Label(text="Miles", padx=10, pady=10, font=("Arial", 10, "bold"))
km_label = Label(text="Km", padx=10, pady=10, font=("Arial", 10, "bold"))
result_label = Label(text=0, padx=10, pady=10, font=("Arial", 10, "bold"))
is_equal_label5 = Label(text="is equal to", padx=10, pady=10, font=("Arial", 10, "bold"))

#button
button = Button(text="Calculate", padx=10, pady=10, command=calc)

#entry
entry = Entry(width=20)

#window_setting
distance_label.grid(column=2, rows=1)
entry.grid(column=2, row=2)
mile_label.grid(column=3, row=2)
is_equal_label5.grid(column=1, row=3)
result_label.grid(column=2, row=3)
km_label.grid(column=3, row=3)
button.grid(column=2, row=4)

window.mainloop()