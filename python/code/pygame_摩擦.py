import pygame
import sys
from pygame.locals import *
from random import *


## 继承这个类
class Ball(pygame.sprite.Sprite):
    ##  缺少边界的话 小球不能弹回来 直接消失了
    def __init__(self,grayball_image,greenball_image,position,speed,bg_size,target):
        pygame.sprite.Sprite.__init__(self)


        # 图片加上 convert_alpha 会有利于你的游戏速度
        self.grayball_image =pygame.image.load(grayball_image).convert_alpha()
        self.greenball_image =pygame.image.load(greenball_image).convert_alpha()
        self.rect = self.grayball_image.get_rect()
        self.rect.left,self.rect.top = position
        self.speed = speed
        self.target = target
        self.control = False
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
    
    def check(self,motion):
        if self.target < motion < self.target + 5:
            return True
        else:
            return False
    
##def collide_check(item,target):
##    col_balls = []
##    for each in target:
##        #  欧氏距离  
##        distance =math.sqrt(
##            math.pow((item.rect.center[0]-each.rect.center[0]),2)+
##            math.pow((item.rect.center[1]-each.rect.center[1]),2)
##            )
##        if distance <= (item.rect.width+each.rect.width) /2:
##            col_balls.append(each)
##
##
##
##    return col_balls
            
## 定义玻璃面板      
class Glass(pygame.sprite.Sprite):
    def __init__(self,glass_image,mouse_image,bg_size):
        ## 初始化动画精灵
        #pygame.sprite.Sprite.__init__(self)
        pygame.sprite.Sprite.__init__(self)

        self.glass_image = pygame.image.load(glass_image).convert_alpha()
        self.glass_rect = self.glass_image.get_rect()
        self.glass_rect.left,self.glass_rect.top = (bg_size[0]-self.glass_rect.width) //2,bg_size[1]-self.glass_rect.height
        self.mouse_image = pygame.image.load(mouse_image).convert_alpha()
        self.mouse_rect = self.mouse_image.get_rect()
        self.mouse_rect.left,self.mouse_rect.top = self.glass_rect.left,self.glass_rect.top

        
        pygame.mouse.set_visible(False)
   
            
        
                



def main():
    pygame.init()
    
    grayball_image = "g:/Py_Self/game/gray_ball.png"
    greenball_image = "g:/Py_Self/game/green_ball.png"
    ##ball_image = "g:/Py_Self/game/ball"
    bg_image = "g:/Py_Self/game/background.png"
    glass_image = "g:/Py_Self/game/glass.png"
    mouse_image = "g:/Py_Self/game/hand.png"

    running = True
    ## 添加背景音乐
    pygame.mixer.music.load("g:/Py_Self/game/bg_music.ogg")
    pygame.mixer.music.play()

    ## 添加音效
    loser_sound = pygame.mixer.Sound("g:/Py_Self/game/loser.wav")
    laugh_sound = pygame.mixer.Sound("g:/Py_Self/game/laugh.wav")

    winner_sound = pygame.mixer.Sound("g:/Py_Self/game/winner.wav")
    hole_sound = pygame.mixer.Sound("g:/Py_Self/game/hole.wav")


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
        ball = Ball(grayball_image,greenball_image,position,speed,bg_size,5*(i+1))
        ## pygame.sprite.collide_circle 完美检测碰撞  
        while pygame.sprite.spritecollide(ball,group,False,pygame.sprite.collide_circle):
            ball.rect.left,ball.rect.top = randint(0,width-100),randint(0,height-100)
            
        balls.append(ball)
        group.add(ball)
    glass = Glass(glass_image,mouse_image,bg_size)
    clock = pygame.time.Clock()
        
    motion =0
    MYTIMER = USEREVENT +1
    pygame.time.set_timer(MYTIMER,1*1000)

    while running:
        for event in pygame.event.get():
            if event.type == QUIT:
                sys.exit()
            elif event.type == GAMEOVER:
                loser_sound.play()
                pygame.time.delay(200)
                laugh_sound.play()
                running = False
            elif event.type == MYTIMER:
                if motion:
                    for each in group:
                        if each.check(motion):
                            each.speed = [0,0]
                            each.control = True
                    motion = 0
            elif event.type == MOUSEMOTION:
                motion +=1
                
                
                
                            
                
        screen.blit(background,(0,0))
        screen.blit(glass.glass_image,glass.glass_rect)
        #限制鼠标只能在玻璃内摩擦摩擦
        glass.mouse_rect.left,glass.mouse_rect.top = pygame.mouse.get_pos()

        ## 考虑 光标 出界的四种情况 
        if glass.mouse_rect.left< glass.glass_rect.left:
            glass.mouse_rect.left = glass.glass_rect.left
            
        if glass.mouse_rect.left > glass.glass_rect.right-glass.mouse_rect.width:
            glass.mouse_rect.left =  glass.glass_rect.right-glass.mouse_rect.width
            
        if glass.mouse_rect.top < glass.glass_rect.top:
            glass.mouse_rect.top = glass.glass_rect.top
            
        if glass.mouse_rect.top > glass.glass_rect.bottom-glass.mouse_rect.height:
            glass.mouse_rect.top = glass.glass_rect.bottom-glass.mouse_rect.height
            
            
        screen.blit(glass.mouse_image,glass.mouse_rect)
            
            
        
        # 移动小球之后 要对其进行检测
        for each in balls:
            each.move()
            if each.control:
                #画绿色小球
                screen.blit(each.greenball_image,each.rect)
            else:
                #  灰色小球
                screen.blit(each.grayball_image,each.rect)
                
           
            
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
        
        
        
    

    
