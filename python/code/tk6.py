from tkinter import *

root = Tk()
GIRLS = ['西施','王昭君','貂蝉','杨玉环']
v =[]
for girl in GIRLS:
    v.append(IntVar())
    # 拿到最后一个数
    b = Checkbutton(root,text=girl,variable= v[-1])
    #排版  注意大写
    b.pack(anchor= W)


    #1.东:East,缩写成E;
    #2.南:South,缩写成S;
    #3.西:West,缩写成W;
    #4.北:North,缩写成N。

mainloop()
