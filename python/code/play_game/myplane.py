import pygame



        

class MyPlane(pygame.sprite.Sprite):
    def __init__(self,bg_size):
        pygame.sprite.Sprite.__init__(self)
        #加载飞机图片
        self.image1 = pygame.image.load("g:/Py_Self/plane/images/me1.png").convert_alpha()
        self.image2 = pygame.image.load("g:/Py_Self/plane/images/me2.png").convert_alpha()
        # 创建一个列表
        self.destroy_images = []
        # 添加四个图片 我方飞机炸毁的画面 
        self.destroy_images.extend([\
            pygame.image.load("g:/Py_Self/plane/images/me_destroy_1.png").convert_alpha(),\
            pygame.image.load("g:/Py_Self/plane/images/me_destroy_2.png").convert_alpha(),\
            pygame.image.load("g:/Py_Self/plane/images/me_destroy_3.png").convert_alpha(),\
            pygame.image.load("g:/Py_Self/plane/images/me_destroy_4.png").convert_alpha()\
            ])
        self.rect = self.image1.get_rect()
        self.width,self.height = bg_size[0],bg_size[1]
        self.rect.left,self.rect.top = \
                                     (self.width-self.rect.width)//2,\
                                     self.height-self.rect.height-60
        # 飞机速度
        self.speed = 10
        # 给我方飞机一个状态 
        self.active = True
        # 我方飞机复活后 在复活的地方恰好有 敌机  则需要设置 三秒无敌
        self.invincible = False
        
        # 代替 spritecollide 碰撞检测   检测非透明部分 
        self.mask = pygame.mask.from_surface(self.image1)
        
        ## 画图顶的位置 是0 下面是位置 height
    def moveUp(self):
        if self.rect.top > 0:
            self.rect.top -= self.speed
        else:
            self.rect.top = 0
    def moveDown(self):
        if self.rect.bottom < self.height - 60:
            self.rect.top +=self.speed
        else:
            self.rect.bottom = self.height - 60
    def moveLeft(self):
        if self.rect.left > 0:
            self.rect.left -= self.speed
        else:
            self.rect.left = 0
    def moveRight(self):
        if self.rect.right < self.width:
            self.rect.left += self.speed
        else:
            self.rect.right = self.width

    # 游戏中角色一般有好几条命 角色死了 可以复活 
    def reset(self):
        self.rect.left,self.rect.top = \
                                     (self.width-self.rect.width)//2,\
                                     self.height-self.rect.height-60
        #通过active 属性来判断是角色是否活着
        self.active = True

        # 我方飞机 三秒无敌
        self.invincible = True

        
            

