from tkinter import *

root = Tk()


'''
listbox = Listbox(root)
listbox.pack(fill=BOTH,expand=True)


for i in  range(10):
    listbox.insert(END,str(i))

'''


Label(root,text='red',bg="red",fg="white").pack(side=LEFT)

Label(root,text='green',bg="green",fg="black").pack(side=LEFT)

Label(root,text='red',bg="blue",fg="white").pack(side=LEFT)


mainloop()
