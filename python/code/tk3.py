from tkinter import *



def callback():
    var.set("吹吧你 我不信")
root = Tk()

frame1 = Frame(root)
frame2 = Frame(root)

var = StringVar()
var.set("您所下载的影片含有未成年人限制内容,\n请满18周岁后再点击")
textLabel=Label(root,
                textvariable=var,
                justify=LEFT)
textLabel.pack(side = LEFT)

photo = PhotoImage(file="g:\\test.gif")
imgLabel = Label(root,image = photo)
imgLabel.pack()

theButton = Button(frame2,text='我已满18岁',command =callback)

theButton.pack()
frame1.pack(padx = 10,pady = 10)
frame2.pack(padx = 10,pady = 10)
mainloop()
