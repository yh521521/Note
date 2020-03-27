from tkinter import *

OPTIONS = [
    "California",
    "458",
    "FF",
    "fll"

    ]
root = Tk()
variable =StringVar()
variable.set(OPTIONS[0])

# * 号 有解包的功能
w = OptionMenu(root,variable,*OPTIONS)
w.pack()
mainloop()
