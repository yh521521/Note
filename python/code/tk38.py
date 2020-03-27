from tkinter import *

root = Tk()

'''

photo = PhotoImage(file = "g:/test.gif")
Label(root,image=photo).pack()


def callback():
    print("正中靶心")
    
    
#  0 最左边 1 最右边  0.5 中间 
Button(root,text="点我",command =callback).place(relx = 0.5,rely = 0.5,anchor= CENTER)
'''



Label(root,bg= "red").place(relx=0.5,rely=0.5,relheight=0.75,relwidth=0.75,anchor = CENTER)
Label(root,bg= "yellow").place(relx=0.5,rely=0.5,relheight=0.5,relwidth=0.5,anchor = CENTER)
Label(root,bg= "green").place(relx=0.5,rely=0.5,relheight=0.25,relwidth=0.25,anchor = CENTER)



mainloop()
