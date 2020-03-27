print('--------我爱鱼C工作室---------')
temp=input('不妨猜一下小甲鱼双在心里想的是哪个数字:')
guess = int(temp)
whie guess  !=8:
    temp=input('哎呀猜错了:')
    guess = int(temp)
    if guess ==8:
        print("我草,你是小甲鱼心里的蛔虫吗?!")
        print("哼,猜中了也没有奖励!")
    else:
        print("猜错了,小甲鱼现在心里的想的的是8")
print("游戏结束,不玩了")
