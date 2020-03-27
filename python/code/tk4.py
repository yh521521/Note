from tkinter import *

root = Tk()
#

photo = PhotoImage(file="g:\\test.gif")
imgLabel = Label(root,
                 text = '学python\n到YH',
                 image = photo,
                 compound=CENTER,
                 font =200)
imgLabel.pack()

mainloop()
