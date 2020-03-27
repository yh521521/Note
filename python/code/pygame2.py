import pygame
import sys

from pygame.locals import *
## 初始化pygame
pygame.init()


size= width,height = 600,400
bg = (255,255,255)  ## rgb 三原色  显示白色



fullscreen = False

#创建指定大小的窗口 surface
screen = pygame.display.set_mode(size,RESIZABLE)
#设置窗口标题
pygame.display.set_caption("初次见面,请大家多多关照")




#加载图片
turtle = pygame.image.load("g:/turtle.jpg")
position = turtle.get_rect()

speed = [5,0]
turtle_right= pygame.transform.rotate(turtle,90)
turtle_top= pygame.transform.rotate(turtle,180)
turtle_left= pygame.transform.rotate(turtle,270)
turtle_bottom= turtle
#turtle = turtle_top #初始从顶部开始

l_head = turtle
r_head = pygame.transform.flip(turtle,True,False)
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
        ##  要导入常量  不导的话要用 pygame .KEYDOWN
        if event.type == KEYDOWN:
            #全屏
            if event.key == K_F11:
                fullscreen = not fullscreen
                ##HWSURFACE 开启硬件加速
                ## 此处设置mode  我知道自己电脑得到分辨率是 1366 X  768
                #但是游戏面对玩家,不能写死
                if fullscreen:
                    screen = pygame.display.set_mode((1366,768),FULLSCREEN | HWSURFACE)
                    width,height = 1366,768
                else:
                    screen = pygame.display.set_mode(size)                

    # 移动图像
    position = position.move(speed)

    if position.right > width:
        turtle = turtle_right
        position = turtle_rect = turtle.get_rect()
        position.left = width -turtle_rect.width
        speed = [0,5]
    if position.bottom > height:
        turtle = turtle_bottom
        position = turtle_rect = turtle.get_rect()
        position.left = width -turtle_rect.width
        position.top = height - turtle_rect.height
        speed = [-5,0]
    if position.left < 0:
        turtle = turtle_left
        position = turtle_rect = turtle.get_rect()
        position.top = height - turtle_rect.height
        speed = [0,-5]
    if position.top <0:
        turtle = turtle_top
        position = turtle_rect = turtle.get_rect()
        speed = [5,0]   

    #填充背景  显示一个画布
    screen.fill(bg)  
    #更新图像  把小乌龟的像素复制到画布上
    screen.blit(turtle,position)
    # 更新界面
    pygame.display.flip()
    #延迟10秒    注释掉的话 图像 会一直乱跑  
    pygame.time.delay(50)
    #设置帧率
    #clock.tick(100)
