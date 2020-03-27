from tkinter import *



root = Tk()

text = Text(root ,width=30,height=5)
text.pack()

text.insert(INSERT,"I love FREEDOM")

text.tag_add("tag1","1.7","1.12","1.2")
text.tag_add("tag2","1.7","1.12","1.2")

text.tag_config("tag1",background="red",foreground="yellow")
##互相覆盖
text.tag_config("tag2",foreground="blue")

mainloop()
