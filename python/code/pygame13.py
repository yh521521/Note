import pygame
import sys
from pygame.locals import *
from random import *
import math

## 继承这个类
class Ball(pygame.sprite.Sprite):
    ##  缺少边界的话 小球不能弹回来 直接消失了
    def __init__(self,image,position,speed,bg_size):
        pygame.sprite.Sprite.__init__(self)


        # 图片加上 convert_alpha 会有利于你的游戏速度
        self.image =pygame.image.load(image).convert_alpha()
        self.rect = self.image.get_rect()
        self.rect.left,self.rect.top = position
        self.speed = speed
        self.width,self.height = bg_size[0],bg_size[1]
        self.radius = self.rect.width /2
        
    def move(self):
        self.rect = self.rect.move(self.speed)
        #
        if self.rect.right <0:
            self.rect.left= self.width
        elif self.rect.left>self.width:
            self.rect.right =0
        elif self.rect.bottom < 0:
            self.rect.top = self.height
        elif self.rect.top > self.height:
            self.rect.bottom=0
def collide_check(item,target):
    col_balls = []
    for each in target:
        #  欧氏距离  
        distance =math.sqrt(
            math.pow((item.rect.center[0]-each.rect.center[0]),2)+
            math.pow((item.rect.center[1]-each.rect.center[1]),2)
            )
        if distance <= (item.rect.width+each.rect.width) /2:
            col_balls.append(each)



    return col_balls
            
        
    



def main():
    pygame.init()
    ball_image = "g:/ball.png"
    bg_image = "g:/background.png"

    running = True
    ## 添加背景音乐
    pygame.mixer.music.load("g:/bg_music.ogg")
    pygame.mixer.music.play()

    ## 添加音效
    loser_sound = pygame.mixer.Sound("g:/loser.ogg")
    laugh_sound = pygame.mixer.Sound("g:/cat.wav")

    winner_sound = pygame.mixer.Sound("g:/winner.ogg")
    hole_sound = pygame.mixer.Sound("g:/dog.wav")


    # 音乐播放完时 游戏结束
    GAMEOVER = USEREVENT
    pygame.mixer.music.set_endevent(GAMEOVER)

    
    bg_size = width,height = 1024,681
    screen = pygame.display.set_mode(bg_size)
    pygame.display.set_caption("play the  ball")
    background =pygame.image.load(bg_image).convert_alpha()
    # 用来存放小球对象的列表
    balls = []
    group = pygame.sprite.Group()
    

    
    # 创建5个小球
    BALL_NUM = 5
    for i in range(BALL_NUM):
        ## 因为是引入随机数 所以每次打开小球的位置都在变化
        position = randint(0,width-100),randint(0,height-100)
        speed= [randint(-10,10),randint(-10,10)]
        ball = Ball(ball_image,position,speed,bg_size)
        ## pygame.sprite.collide_circle 完美检测碰撞  
        while pygame.sprite.spritecollide(ball,group,False,pygame.sprite.collide_circle):
            ball.rect.left,ball.rect.top = randint(0,width-100),randint(0,height-100)
            
        balls.append(ball)
        group.add(ball)
    clock = pygame.time.Clock()
        
    

    while running:
        for event in pygame.event.get():
            if event.type == QUIT:
                sys.exit()
            elif event.type == GAMEOVER:
                loser_sound.play()
                pygame.time.delay(200)
                laugh_sound.play()
                running = False
                
                
        screen.blit(background,(0,0))

        # 移动小球之后 要对其进行检测
        for each in balls:
            each.move()
            screen.blit(each.image,each.rect)
            
        for each in group:
            group.remove(each)
            if pygame.sprite.spritecollide(each,group,False,pygame.sprite.collide_circle):
                each.speed[0] = -each.speed[0]
                each.speed[1] = -each.speed[1]
            group.add(each)
            
##        for i in range(BALL_NUM):
##            item = balls.pop(i)
##            if collide_check(item,balls):
##                item.speed[0] = -item.speed[0]
##                item.speed[1] = -item.speed[1]
##            ## 拿出来的球 还要放回去
##            balls.insert(i,item)
            
            
        pygame.display.flip()
        clock.tick(30)

        
if __name__ == '__main__':
    main()
        
        
        
    

    
