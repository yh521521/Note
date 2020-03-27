from tkinter import *


root = Tk()
#Canvas画布
w = Canvas(root,width=200,height=100)
w.pack()
##dash=(4,4)  画出来的是虚线
w.create_rectangle(40,20,160,80,dash=(4,4))

#创建椭圆
## 画椭圆的话先画一个矩形  然后继续画椭圆 给它填充  坐标要一致
### 圆形是特殊的椭圆
w.create_oval(40,20,160,80,fill="pink")
w.create_text(100,50,text="Freedom")


mainloop()
