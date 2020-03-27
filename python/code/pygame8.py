import pygame
import sys
from pygame.locals import *

##画椭圆的话首先要画出限定矩形


pygame.init()

WHITE = (255,255,255)
BLACK = (0,0,0)
GREEN =(0,255,0)
RED = (255,0,0)
BLUE =(0,0,255)
size = width,height = 640,300

screen = pygame.display.set_mode(size)
pygame.display.set_caption("love freedom")





clock =pygame.time.Clock()




while True:
    for event in pygame.event.get():
        if event.type == QUIT:
            sys.exit()
       
            
    screen.fill(WHITE)
    ## 此处画椭圆  (100,100) 的位置画一个限定矩形  和一个限定正方形 得到
    # 的椭圆是 圆  和椭圆  边框为 1    
    pygame.draw.ellipse(screen,BLACK,(100,100,440,100),1)
    pygame.draw.ellipse(screen,BLACK,(220,50,200,200),1)
        
    ##  双缓冲的方法  图是放在内存中的   
    pygame.display.flip()

    clock.tick(120)

   
        
