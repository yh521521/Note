from tkinter import *


root =Tk()


w1 = Message(root,text="这是一则消息",width=100)
w1.pack()

w2 = Message(root,text="这是一则\n好很好非常好的消息",width=100)
w2.pack()


mainloop()
