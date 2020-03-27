import pygame
import sys
from pygame.locals import *

pygame.init()

size = width,height= 640,480

bg = (0,0,0)

clock = pygame.time.Clock()
screen = pygame.display.set_mode(size)
pygame.display.set_caption("love freedom")

turtle = pygame.image.load("g:/turtle.png").convert_alpha()
background = pygame.image.load("g:/background.jpg").convert()
position= turtle.get_rect()
position.center =width //2,height //2

##turtle.set_colorkey((255,255,255))
#turtle.set_alpha(200 )

#print(turtle.get_at(position.center))


def blit_alpha(target,source,location,opacity):
    x= location[0]
    y=location[1]
    temp = pygame.Surface((source.get_width(),source.get_height())).convert()
    temp.blit(target,(-x,-y))
    temp.blit(source,(0,0))
    temp.set_alpha(opacity)
    target.blit(temp,location)



##for i in range(position.width):
##    for j in range(position.height):
##        temp = turtle.get_at((i,j))
##
##        if temp[3]!= 0:
##            temp[3] == 200
##        turtle.set_at((i,j),temp)
##    

while True:
    for event in pygame.event.get():
        if event.type == QUIT:
            sys/exit()
                       
    screen.blit(background,(0,0))
##    screen.blit(turtle,position)
    blit_alpha(screen,turtle,position,200)
        
    
    pygame.display.flip()

    clock.tick(30)
        
