from tkinter import *

root = Tk()






Label(root,text="用户名").grid(row=0,sticky = W)
Label(root,text="密码").grid(row =1,sticky = W)


photo =PhotoImage(file="g:/test.gif")
Label(root,image=photo).grid(row=1,column=2,rowspan=10)

Entry(root).grid(row =0,column=1)
###  密码 用 ?显示
Entry(root,show="?").grid(row=1,column=1)



Button(text = "提交",width="10").grid(row=2,columnspan =3,pady=5)

mainloop()
