import pygame
import sys
from pygame.locals import *


pygame.init()
# 初始化扩音器
pygame.mixer.init()

pygame.mixer.music.load("g:/bg_music.ogg")
#设置音量
pygame.mixer.music.set_volume(0.2)
#开始播放
pygame.mixer.music.play()

##加载音效
cat_sound = pygame.mixer.Sound("g:/cat.wav")
cat_sound.set_volume(0.2)
dog_sound = pygame.mixer.Sound("g:/dog.wav")
dog_sound.set_volume(0.2)



bg_size = width,height = 300,200

screen = pygame.display.set_mode(bg_size)
pygame.display.set_caption("Musci -YH")

pause = False

pause_image = pygame.image.load("g:/pause.png").convert_alpha()
unpause_image = pygame.image.load("g:/unpause.png").convert_alpha()
pause_rect = pause_image.get_rect()
pause_rect.left,pause_rect.top=(width-pause_rect.width) // 2,(height-pause_rect.height)//2


clock = pygame.time.Clock()


while True:
    for event in pygame.event.get():
        if event.type == QUIT:
            sys.exit()
        if event.type == MOUSEBUTTONDOWN:
            ## 1 左键
            if event.button ==1:
                cat_sound.play()
            # 3 右键
            if event.button == 3:
                dog_sound.play()
        if event.type == KEYDOWN:
            if event.key == K_SPACE:
                pause = not pause
    screen.fill((255,255,255))

    if pause:
        # 绘制按钮  true 
        screen.blit(pause_image,pause_rect)
        pygame.mixer.music.pause()
    else:
        screen.blit(unpause_image,pause_rect)
        pygame.mixer.music.unpause()
    # 从内存中刷新   设置 为30 帧
    pygame.display.flip()
    clock.tick(30)
        
        
    
                
                
