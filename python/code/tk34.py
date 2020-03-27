from tkinter import *


##root =Tk()


##w= Spinbox(root,from_=0,to=10)
##w= Spinbox(root,values=("小甲鱼","--风介","微笑啊","戴宇轩"))
#w.pack()
'''
m= PanedWindow(orient=VERTICAL)
m.pack(fill= BOTH,expand=1)

top = Label(m,text="top pane")
m.add(top)

botton = Label(m,text="button pane")
m.add(botton)
'''

'''
m1= PanedWindow()
m1.pack(fill= BOTH,expand=1)

left = Label(m1,text="left pane")
m1.add(left)

m2= PanedWindow(orient=VERTICAL)
m1.add(m2)

top = Label(m2,text="top pane")
m2.add(top)

buttom = Label(m2,text="bottom pane")
m2.add(buttom)


'''


##向下凹
m1= PanedWindow(showhandle=True,sashrelief=SUNKEN)
m1.pack(fill= BOTH,expand=1)

left = Label(m1,text="left pane")
m1.add(left)

m2= PanedWindow(orient=VERTICAL,showhandle=True,sashrelief=SUNKEN)
m1.add(m2)

top = Label(m2,text="top pane")
m2.add(top)

buttom = Label(m2,text="bottom pane")
m2.add(buttom)


mainloop()
