import pygame
from random import*


#补给包

## 子弹补给包
class Bullet_Supply(pygame.sprite.Sprite):
    def __init__(self,bg_size):
        pygame.sprite.Sprite.__init__(self)

        self.image = pygame.image.load("g:/Py_Self/plane/images/bullet_supply.png").convert_alpha()
        self.rect = self.image.get_rect()
        self.width,self.height = bg_size[0],bg_size[1]
        
        # 补给包是从上往下扔  bottom 底部  注意画板 bottom 在上面
        self.rect.left,self.rect.bottom = \
                                    randint(0,self.width - self.rect.width),-100
        self.speed = 5
        self.active = False
        self.mask = pygame.mask.from_surface(self.image)

    def move(self):
        if self.rect.top < self.height:
            self.rect.top += self.speed
        else:
            self.active  = False

    def reset(self):
        self.active = True
        self.rect.left,self.rect.bottom = \
                                        randint(0,self.width -self.rect.width),-100
                                
                                    

#全屏炸弹补给包       
class Bomb_Supply(pygame.sprite.Sprite):
    def __init__(self,bg_size):
        pygame.sprite.Sprite.__init__(self)

        self.image = pygame.image.load("g:/Py_Self/plane/images/bomb_supply.png").convert_alpha()
        self.rect = self.image.get_rect()
        self.width,self.height = bg_size[0],bg_size[1]
        # 补给包是从上往下扔  bottom 底部  注意画板 bottom 在上面
        self.rect.left,self.rect.bottom = \
                                    randint(0,self.width - self.rect.width),-100
        self.speed = 5
        self.active = False
        self.mask = pygame.mask.from_surface(self.image)

    def move(self):
        if self.rect.top < self.height:
            self.rect.top += self.speed
        else:
            self.active  = False

    def reset(self):
        self.active = True
        self.rect.left,self.rect.bottom = \
                                        randint(0,self.width -self.rect.width),-100
