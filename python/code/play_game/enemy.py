import pygame
from random import *

##  该类为敌机  三种类型 小 中  大
## 飞机被炸毁  状态会改变 按顺序显示飞机炸毁的画面 每炸毁一个飞机 就有一个新的飞机诞生

# 小型机
class SmallEnemy(pygame.sprite.Sprite):
    def __init__(self,bg_size):
        # 初始化动画精灵
        pygame.sprite.Sprite.__init__(self)

        self.image = pygame.image.load("g:/Py_Self/plane/images/enemy1.png").convert_alpha()
        # 创建一个列表
        self.destroy_images = []
        # 添加四个图片 敌方小型飞机炸毁的画面 
        self.destroy_images.extend([\
            pygame.image.load("g:/Py_Self/plane/images/enemy1_down1.png").convert_alpha(),\
            pygame.image.load("g:/Py_Self/plane/images/enemy1_down2.png").convert_alpha(),\
            pygame.image.load("g:/Py_Self/plane/images/enemy1_down3.png").convert_alpha(),\
            pygame.image.load("g:/Py_Self/plane/images/enemy1_down4.png").convert_alpha()\
            ])
        self.rect = self.image.get_rect()
        self.width,self.height = bg_size[0],bg_size[1]
        self.speed = 2
        self.active = True
        self.rect.left,self.rect.top = \
                                     randint(0,self.width - self.rect.width),\
                                     randint(-5 * self.height,0)

        #  非透明部分检测
        self.mask = pygame.mask.from_surface(self.image)
    def move(self):
        if self.rect.top < self.height:
            self.rect.top += self.speed
        else:
            # 重置
            self.reset()

    def reset(self):
        self.active = True
        self.rect.left,self.rect.top = \
                                     randint(0,self.width - self.rect.width),\
                                     randint(-5 * self.height,0)
   
# 中型机    
class MidEnemy(pygame.sprite.Sprite):

    #飞机的血条
    energy = 8 
    
    def __init__(self,bg_size):
        # 初始化动画精灵
        pygame.sprite.Sprite.__init__(self)

        self.image = pygame.image.load("g:/Py_Self/plane/images/enemy2.png").convert_alpha()
        ## 被击中的画面
        self.image_hit = pygame.image.load("g:/Py_Self/plane/images/enemy2_hit.png").convert_alpha()

        # 创建一个列表
        self.destroy_images = []
        # 添加四个图片 敌方中型飞机炸毁的画面 
        self.destroy_images.extend([\
            pygame.image.load("g:/Py_Self/plane/images/enemy2_down1.png").convert_alpha(),\
            pygame.image.load("g:/Py_Self/plane/images/enemy2_down2.png").convert_alpha(),\
            pygame.image.load("g:/Py_Self/plane/images/enemy2_down3.png").convert_alpha(),\
            pygame.image.load("g:/Py_Self/plane/images/enemy2_down4.png").convert_alpha()\
            ])

        self.rect = self.image.get_rect()
        self.width,self.height = bg_size[0],bg_size[1]
        self.speed = 1
        self.active = True
        self.rect.left,self.rect.top = \
                                     randint(0,self.width - self.rect.width),\
                                     randint(-10 * self.height,-self.height)

        self.mask = pygame.mask.from_surface(self.image)
        self.energy = MidEnemy.energy
        # 默认是没有被击中
        self.hit = False
    def move(self):
        if self.rect.top < self.height:
            self.rect.top += self.speed
        else:
            # 重置
            self.reset()

    def reset(self):
        self.active = True
        self.energy = MidEnemy.energy
        self.rect.left,self.rect.top = \
                                     randint(0,self.width - self.rect.width),\
                                     randint(-10 * self.height,-self.height)
# 大型机   
class BigEnemy(pygame.sprite.Sprite):

     #飞机的血条
    energy = 20
    
    def __init__(self,bg_size):
        # 初始化动画精灵
        pygame.sprite.Sprite.__init__(self)

        self.image1 = pygame.image.load("g:/Py_Self/plane/images/enemy3_n1.png").convert_alpha()
        self.image2 = pygame.image.load("g:/Py_Self/plane/images/enemy3_n2.png").convert_alpha()
        ## 被击中的画面
        self.image_hit = pygame.image.load("g:/Py_Self/plane/images/enemy3_hit.png").convert_alpha()

        # 创建一个列表
        self.destroy_images = []
        # 添加四个图片 敌方大型飞机炸毁的画面 
        self.destroy_images.extend([\
            pygame.image.load("g:/Py_Self/plane/images/enemy3_down1.png").convert_alpha(),\
            pygame.image.load("g:/Py_Self/plane/images/enemy3_down2.png").convert_alpha(),\
            pygame.image.load("g:/Py_Self/plane/images/enemy3_down3.png").convert_alpha(),\
            pygame.image.load("g:/Py_Self/plane/images/enemy3_down4.png").convert_alpha(),\
            pygame.image.load("g:/Py_Self/plane/images/enemy3_down5.png").convert_alpha(),\
            pygame.image.load("g:/Py_Self/plane/images/enemy3_down6.png").convert_alpha()\
            ])
        self.rect = self.image1.get_rect()
        self.width,self.height = bg_size[0],bg_size[1]
        self.active = True
        self.speed = 1
        self.rect.left,self.rect.top = \
                                     randint(0,self.width - self.rect.width),\
                                     randint(-15 * self.height,-5 * self.height)

        self.mask = pygame.mask.from_surface(self.image1)
        self.energy = BigEnemy.energy
        # 默认是没有被击中
        self.hit = False
    def move(self):
        if self.rect.top < self.height:
            self.rect.top += self.speed
        else:
            # 重置
            self.reset()

    def reset(self):
        self.active = True
        self.energy = BigEnemy.energy
        self.rect.left,self.rect.top = \
                                     randint(0,self.width - self.rect.width),\
                                     randint(-15 * self.height,-5 * self.height)
   
                                         
        
    
            
