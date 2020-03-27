import pygame
import sys
from pygame.locals import *
from random import *
import traceback

## 继承这个Sprite类
class Ball(pygame.sprite.Sprite):
    ##  缺少边界的话 小球不能弹回来 直接消失了
    def __init__(self,grayball_image,greenball_image,position,speed,bg_size,target):
        # 初始化动画精灵
        pygame.sprite.Sprite.__init__(self)


        # 图片加上 convert_alpha 会有利于你的游戏速度
        self.grayball_image =pygame.image.load(grayball_image).convert_alpha()
        self.greenball_image =pygame.image.load(greenball_image).convert_alpha()
        self.rect = self.grayball_image.get_rect()

        #将小球放在指定位置
        self.rect.left,self.rect.top = position
        #小球方向属性
        self.side = [choice([-1,1]),choice([-1.1])]
        self.speed = speed
        # collide 碰撞属性   false 未相撞  true 相撞
        self.collide = False 
        
        self.target = target
        # 两个球相撞就变成失控状态
        self.control = False # false 失控状态 true  控值状态
        self.width,self.height = bg_size[0],bg_size[1]
        self.radius = self.rect.width /2
        
    def move(self):

        if self.control:
            self.rect = self.rect.move(self.speed)
        else:
            self.rect = self.rect.move(self.side[0]*self.speed[0],\
                                   self.side[1]*self.speed[1])
        #  如果小球的左侧出了边界 那魔将小球左侧的位置改为右侧的边界
        #这样便实现了从左边进入 右边出来的效果
        if self.rect.right <=0:
            self.rect.left= self.width
        elif self.rect.left>=self.width:
            self.rect.right =0
        elif self.rect.bottom <= 0:
            self.rect.top = self.height
        elif self.rect.top >= self.height:
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
    ## 图像地址
    grayball_image = "g:/Py_Self/game/gray_ball.png"
    greenball_image = "g:/Py_Self/game/green_ball.png"
    bg_image = "g:/Py_Self/game/background.png"
    glass_image = "g:/Py_Self/game/glass.png"
    mouse_image = "g:/Py_Self/game/hand.png"

    running = True
    ## 添加背景音乐
    pygame.mixer.music.load("g:/Py_Self/game/bg_music.ogg")
    pygame.mixer.music.play()

    ## 添加音效
    # 失败
    loser_sound = pygame.mixer.Sound("g:/Py_Self/game/loser.wav")
    #嘲笑
    laugh_sound = pygame.mixer.Sound("g:/Py_Self/game/laugh.wav")
    ##成功
    winner_sound = pygame.mixer.Sound("g:/Py_Self/game/winner.wav")
    # 进洞音效
    hole_sound = pygame.mixer.Sound("g:/Py_Self/game/hole.wav")


    # 音乐播放完时 游戏结束
    GAMEOVER = USEREVENT
    pygame.mixer.music.set_endevent(GAMEOVER)

    
    bg_size = width,height = 1024,681
    screen = pygame.display.set_mode(bg_size)
    pygame.display.set_caption("play the  ball")
    background =pygame.image.load(bg_image).convert_alpha()


     # 5个坑的范围，因为100%命中太难，所以只要在范围内即可
    # 每个元素：(x1,x2,y1,y2)
    hole = [(117,119,119,201),(225,227,390,392),\
            (503,505,320,322),(698,700,192,194),\
            (906,908,419,421)]
    #消息列表
    msgs = [] 

    # 用来存放小球对象的列表
    balls = []
    group = pygame.sprite.Group()
    

    
    # 创建5个小球
    BALL_NUM = 5
    for i in range(BALL_NUM):
        ## 因为是引入随机数 所以每次打开小球的位置都在变化
        position = randint(0,width-100),randint(0,height-100)
        speed= [randint(1,10),randint(1,10)]
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

    pygame.key.set_repeat(100,100)
    
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
            elif event.type == KEYDOWN:
                if event.key == K_w:
                    for each in group:
                        if each.control:
                            each.speed[1] -= 1
                if event.key == K_s:
                    for each in group:
                        if each.control:
                            each.speed[1] += 1
                if event.key == K_a:
                    for each in group:
                        if each.control:
                            each.speed[0] -= 1
                if event.key == K_d:
                    for each in group:
                        if each.control:
                            each.speed[0] += 1
                if event.key == K_SPACE:
                    for each in group:
                        if each.control:
                            ## 小球进洞逻辑
                            for i in hole:
                                if i[0] <= each.rect.left <= i[1] and \
                                   i[2] <= each.rect.top <= i[3]:
                                    hole_sound.play()
                                    each.speed=[0,0]
                                    group.remove(each)
                                    temp = balls.pop(balls.index(each))
                                    balls.insert(0,temp)
                                    hole.remove(i)
                                # 如果所有的球都进洞 结束
                                if not hole:
                                    pygame.mixer.music.stop()
                                    winner_sound.play()
                                    pygame.time.delay(3000)
                                    # 打印信息
                                    msg = pygame.image.load("g:/turtle.png")
                                    msg_pos = (width -msg.get_width()) // 2,\
                                              (height-msg.get_height()) //2
                                    msgs.append((msg,msg_pos))
                                    laugh_sound.play()
                                    

                                        
                                    
                
                            
                
                
                
                
                            
                
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
            if each.collide:
                # 如果小球相撞 才会修改小球速度
                each.speed=[randint(1,10),randint(1,10)]
                # 然后 在修改collide 的值
                each.collide = False
                
            
            if each.control:
                #画绿色小球
                screen.blit(each.greenball_image,each.rect)
            else:
                #  灰色小球
                screen.blit(each.grayball_image,each.rect)
                
           
            
        for each in group:
            group.remove(each)
            if pygame.sprite.spritecollide(each,group,False,pygame.sprite.collide_circle):
                
                # 相撞之后给一个随机速度  速度是 带方向的  如果相撞之后 速度方向还是相向的 就会再次相撞 缠在一起
                # 直到某个时刻 随机速度的方向相反 才会分开
                #
                each.side[0] = -each.side[0]
                each.side[1] = -each.side[1]
                each.collide = True
                if each.control:
                    each.side[0] = -1
                    each.side[1] = -1
                #  each.speed[0] = -each.speed[0]
               #  each.speed[1] = -each.speed[1]
                #  灰色撞绿色 绿色撞绿色 灰色撞灰色  只要相撞 球就失控
                    each.control = False
            group.add(each)
            
##        for i in range(BALL_NUM):
##            item = balls.pop(i)
##            if collide_check(item,balls):
##                item.speed[0] = -item.speed[0]
##                item.speed[1] = -item.speed[1]
##            ## 拿出来的球 还要放回去
##            balls.insert(i,item)
        for msg in msgs:
            screen.blit(msg[0],msg[1])
            
        pygame.display.flip()
        clock.tick(30)

        
if __name__ == '__main__':
    try:
        main()
    except SystemExit:
        pass
    except:
        traceback.print_exec()
        pygame.quit()
        input()
        
        
    
    
        
        
        
    

    
