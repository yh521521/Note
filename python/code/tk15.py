from tkinter import *


root = Tk()

text = Text(root,width=30,height=30)

text.pack()

text.insert(INSERT,'I love \n  ')

text.insert(END,'FishC.com!')


photo =PhotoImage(file = 'g:/test.gif')

def show():
    text.image_create(END,image=photo)
    

b1=Button(text,text="点我",command=show)
text.window_create(INSERT,window=b1)
mainloop()
