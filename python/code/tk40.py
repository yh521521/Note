import pygame
import sys

from pygame.locals import *
## 初始化pygame
pygame.init()

clock= pygame.time.Clock()
size= width,height = 600,400
speed = [-2,1]
bg = (255,255,255)  ## rgb 三原色  显示白色

fullscreen = False

#创建指定大小的窗口 surface
screen = pygame.display.set_mode(size,RESIZABLE)
#设置窗口标题
pygame.display.set_caption("初次见面,请大家多多关照")

# 设置放大缩小的比率
ratio = 1.0


#加载图片
oturtle = pygame.image.load("g:/turtle.jpg")
turtle = oturtle
oturtle_rect = oturtle.get_rect()
position = turtle_rect =oturtle_rect

l_head = turtle
r_head = pygame.transform.flip(turtle,True,False)
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
        ##  要导入常量  不导的话要用 pygame .KEYDOWN
        if event.type == KEYDOWN:
            if event.key == K_LEFT:
                speed = [-1,0]
                
            if event.key == K_RIGHT:
                turtle = r_head
                speed = [1,0]
            
            if event.key == K_UP:
                
                speed = [0,-1]

            if event.key == K_DOWN:
                
                speed = [0,1]
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
                ## 放大缩小小乌龟(= - ) 空格 键 恢复原始尺寸
            if event.key == K_EQUALS or event.key == K_MINUS or event.key == K_SPACE:
                # 最大智能放大一倍 ,缩小50%
                if event.key == K_EQUALS and ratio< 2:
                    ratio +=0.1
                if event.key == K_MINUS and ratio > 0.5:
                    ratio -=0.1
                if event.key == K_SPACE:
                    ratio = 1.0
                turtle =pygame.transform.smoothscale(oturtle,
                                                      (int(oturtle_rect.width*ratio),
                                                      int(oturtle_rect.height*ratio)))
                l_head = turtle
                r_head = pygame.transform.flip(turtle,True,False)
                    
    ## 用户调整窗口尺寸
    if event.type == VIDEORESIZE:
        size = event.size
        width,height = size
        print(size)
        screen = pygame.display.set_mode(size,RESIZABLE)
        
                

    # 移动图像
    position = position.move(speed)

    if position.left < 0 or position.right > width:
        # 翻转图像
        turtle = pygame.transform.flip(turtle,True,False)
        #反方向移动
        speed[0] = -speed[0]
    if position.top < 0 or position.bottom > height:
        speed[1] = -speed[1]

    #填充背景  显示一个画布
    screen.fill(bg)  
    #更新图像  把小乌龟的像素复制到画布上
    screen.blit(turtle,position)
    # 更新界面
    pygame.display.flip()
    #延迟10秒    注释掉的话 图像 会一直乱跑  
    #pygame.time.delay(10)
    #设置帧率
    clock.tick(100)