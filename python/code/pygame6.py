import pygame
import sys
from pygame.locals import *

pygame.init()

WHITE = (255,255,255)
BLACK = (0,0,0)
bg = (0,0,0)

GREEN =(0,255,0)
points = [(200,75),(300,25),(400,75),(450,25),(450,125),(400,75),(300,125)]

size = width,height = 649,200

screen = pygame.display.set_mode(size)
pygame.display.set_caption("love freedom")

clock =pygame.time.Clock()




while True:
    for event in pygame.event.get():
        if event.type == QUIT:
            sys.exit()
    screen.fill(WHITE)
    pygame.draw.polygon(screen,GREEN,points,0)
  
        
    ##  双缓冲的方法  图是放在内存中的   
    pygame.display.flip()

    clock.tick(30)

   
        
