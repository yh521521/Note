from tkinter import *


master = Tk()

theLB = Listbox(master,selectmode=EXTENDED)
theLB.pack()


#添加选项
'''
theLB.insert(0,'你是谁')
theLB.insert(END,'不告诉你')
'''

for item in['鸡蛋','鸭蛋','鹅蛋','我是狗蛋']:
    theLB.insert(END,item)

## theLB.delete(1)
theButton=Button(master,text='删除它',
                 command=lambda x=theLB:x.delete(ACTIVE))

theButton.pack()
mainloop()

