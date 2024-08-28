from tkinter import *
from datetime import datetime
import pandas

# ---------------------------- CONSTANTS ------------------------------- #
PINK = "#e2979c"
RED = "#e7305b"
GREEN = "#9bdeac"
YELLOW = "#f7f5dd"
FONT_NAME = "Courier"
WORK_MIN = 1
SHORT_BREAK_MIN = 1
LONG_BREAK_MIN = 1
REPS = 0
timer = None
log = []


# ---------------------------- TIMER RESET ------------------------------- #
def reset_timer():
    global REPS, log
    window.after_cancel(timer)
    canvas.itemconfig(timer_text, text=f"00:00")
    timer_for.config(text="Timer Not Started", fg=GREEN)
    check_mark_label.config(text="")
    REPS = 0
    log.append(f"Reset Done at {datetime.now()}")
    print(f"Reset Done at {datetime.now()}")


# ---------------------------- TIMER MECHANISM ------------------------------- # 
def start_timer():
    global REPS
    REPS += 1
    work_sec = WORK_MIN*60
    short_break_sec = SHORT_BREAK_MIN*60
    long_break_sec = LONG_BREAK_MIN*60

    if REPS % 8 == 0:
        log.append(f"Long Break Timer Started at {datetime.now()}")
        print(f"Long Break Timer Started at {datetime.now()}")
        count_down(long_break_sec)
        timer_for.config(text="Long Break Time", fg=RED)
    elif REPS % 2 == 0:
        log.append(f"Short Break Timer Started at {datetime.now()}")
        print(f"Short Break Timer Started at {datetime.now()}")
        count_down(short_break_sec)
        timer_for.config(text="Short Break Time", fg=PINK)
    else:
        log.append(f"Work Timer Started at {datetime.now()}")
        print(f"Work Timer Started at {datetime.now()}")
        count_down(work_sec)
        timer_for.config(text="Work Time", fg=GREEN)


# ---------------------------- COUNTDOWN MECHANISM ------------------------------- #
def count_down(count):
    count_min = count // 60
    count_sec = count % 60
    if count_min < 10:
        count_min = f"0{count_min}"

    if count_sec == 0:
        count_sec = "00"
    elif count < 10:
        count_sec = f"0{count_sec}"

    canvas.itemconfig(timer_text, text=f"{count_min}:{count_sec}")

    if count > 0:
        global timer
        timer = window.after(1000, count_down, count - 1)
    else:
        start_timer()
        marks = ""
        for _ in range(REPS//2):
            marks += "✔"
        check_mark_label.config(text=marks)


# ---------------------------- UI SETUP ------------------------------- #
# window
window = Tk()
window.title("Pomodoro")
window.config(padx=200, pady=50, bg=YELLOW)
window.minsize(width=600, height=500)

# canvas
canvas = Canvas(width=200, height=224, bg=YELLOW, highlightbackground=YELLOW)
tomato_img = PhotoImage(file="tomato.png")
canvas.create_image(102, 112, image=tomato_img)
timer_text = canvas.create_text(102, 130, text="00:00", fill="white", font=(FONT_NAME, 28, "bold"))
canvas.grid(column=2, row=2)

# label
headline_label = Label(text="Timer", fg=GREEN, bg=YELLOW, font=(FONT_NAME, 30, "bold"))
headline_label.grid(column=2, row=1)
timer_for = Label(text="Timer Not Started", fg=GREEN, bg=YELLOW, font=(FONT_NAME, 15, "bold"), padx=10, pady=10)
timer_for.grid(column=2, row=3)
check_mark_label = Label(fg=GREEN, bg=YELLOW, font=(FONT_NAME, 15))
check_mark_label.grid(column=2, row=4)


# button
start_button = Button(text="Start", padx=10, pady=10, font=(FONT_NAME, 10, "bold"), fg=RED, command=start_timer)
reset_button = Button(text="Reset", padx=10, pady=10, font=(FONT_NAME, 10, "bold"), fg=RED, command=reset_timer)
start_button.grid(column=1, row=4)
reset_button.grid(column=3, row=4)

window.mainloop()

log_dict = {"Log": log}
log_file = pandas.DataFrame(log_dict)
log_file.to_csv("log.csv")
print("Get Your Report in log.csv")
