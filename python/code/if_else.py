
    
print('-------爱你鱼C---------')
temp = input('你输入的数字是啥呢:')
guess = int(temp)
while guess != 8:
    temp = input('猜错了,不妨在输入一次:')
    guess = int(temp)
    if guess == 8:
        print("一下子就猜中了")
        print("不玩了")
    else:
        if guess > 8:
            print("大了大了")
        else:
            print("小了小了")
print("游戏结束不玩了")
