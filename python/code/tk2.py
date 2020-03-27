import tkinter as tk

class App:
    def __init__(self,master):
        frame = tk.Frame(master)
        frame.pack(side=tk.LEFT,padx = 100,pady=100)
        self.hi_there= tk.Button(frame,text='打招呼',fg = 'blue',bg='red',command=self.say_hi)
        self.hi_there.pack()
    def say_hi(self):
        print('你们好')

root = tk.Tk()
app = App(root)

root.mainloop()
