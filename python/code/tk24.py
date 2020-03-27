from tkinter import *

import math as m

root = Tk()

w = Canvas(root,width=200,height=100)
w.pack()


## 五角星的中心点
center_x = 100
center_y = 50

r = 50
points=[
    # 第一个点  左上点 A 
    center_x - int(r*m.sin(2*m.pi /5)),
    center_y - int(r*m.cos(2*m.pi /5)),
    # 右上点 C  72
    center_x + int(r*m.sin(2*m.pi/5)),
    center_y - int(r*m.cos(2*m.pi/5)),
    # 左下角点E  36
    center_x -int(r*m.sin(m.pi /5)),
    center_y +int(r*m.cos(m.pi/5)),

    #顶点 B
    center_x ,
    center_y -r,

    #右下角 的点 D 36
    center_x + int(r*m.sin(m.pi /5)),
    center_y + int(r*m.cos(m.pi/5))
    ]
## 画线 AC
w.create_polygon(points,outline="green",fill="")








mainloop()
