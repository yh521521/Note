import pygame
## 定义 子弹 子弹居中 往上面发射


#  普通子弹
class Bullet1(pygame.sprite.Sprite):
    def __init__(self,position):
        pygame.sprite.Sprite.__init__(self)

        self.image = pygame.image.load("g:/Py_Self/plane/images/bullet1.png").convert_alpha()
        self.rect = self.image.get_rect()
        #定义子弹 位置
        self.rect.left,self.rect.top = position
        #定义子弹速度  比飞机速度块
        self.speed = 12
        # 定义子弹的状态
        self.active = False
        # 完美碰撞检测 
        self.mask = pygame.mask.from_surface(self.image)
        
    def move(self):
        self.rect.top -=self.speed

        if self.rect.top < 0:
            self.active = False
            
    def reset(self,position):
        self.rect.left,self.rect.top = position
        self.active = True
            
# 超级子弹         
class Bullet2(pygame.sprite.Sprite):
    def __init__(self,position):
        pygame.sprite.Sprite.__init__(self)

        self.image = pygame.image.load("g:/Py_Self/plane/images/bullet2.png").convert_alpha()
        self.rect = self.image.get_rect()
        #定义子弹 位置
        self.rect.left,self.rect.top = position
        #定义子弹速度  比飞机速度块
        self.speed = 14
        # 定义子弹的状态
        self.active = False
        # 完美碰撞检测 
        self.mask = pygame.mask.from_surface(self.image)
        
    def move(self):
        self.rect.top -=self.speed

        if self.rect.top < 0:
            self.active = False
            
    def reset(self,position):
        self.rect.left,self.rect.top = position
        self.active = True
