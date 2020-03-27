from tkinter import *


root =Tk()


##  相对于的点击事件的位置
def callback(event):
    #print("当前位置:"event.char)
    print("当前位置:",event.x,event.y)

frame=Frame(root,width=200,height=200)

# 鼠标 1 左键
#frame.bind("<Button-1>",callback)

frame.bind("<Key>",callback)
frame.focus_set()
frame.pack()



mainloop()
