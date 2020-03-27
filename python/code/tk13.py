from tkinter import *

'''
master = Tk()

theLB = Listbox(master,selectmode=EXTENDED,height =11)
theLB.pack()

for item in range(11):
    theLB.insert(END,item)
'''

root = Tk()
sb = Scrollbar(root)
sb.pack(side = RIGHT,fill=Y)

lb=Listbox(root,yscrollcommand=sb.set)

for i in range(1000):
    lb.insert(END,i)
lb.pack(side = LEFT,fill=BOTH)

sb.config(command = lb.yview)
mainloop()
