import pygame
import sys
from pygame.locals import *

pygame.init()

WHITE = (255,255,255)
BLACK = (0,0,0)
bg = (0,0,0)

GREEN =(0,255,0)
points = [(200,75),(300,25),(400,75),(450,25),(450,125),(400,75),(300,125)]

size = width,height = 640,400

screen = pygame.display.set_mode(size)
pygame.display.set_caption("love freedom")

clock =pygame.time.Clock()




while True:
    for event in pygame.event.get():
        if event.type == QUIT:
            sys.exit()
    screen.fill(WHITE)
    # 0 画出来的是未闭合的图像  1画出来的图像是闭合的图像
    pygame.draw.lines(screen,GREEN,1,points,1)
    pygame.draw.line(screen,BLACK,(100,200),(540,250),1)
    #1表示是否看锯齿
    pygame.draw.aaline(screen,BLACK,(100,250),(540,300),1)
    pygame.draw.aaline(screen,BLACK,(100,250),(540,400),0)
  
        
    ##  双缓冲的方法  图是放在内存中的   
    pygame.display.flip()

    clock.tick(30)

   
        
