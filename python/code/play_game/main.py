import pygame
import sys
#导入异常模块
import traceback
# 导入常量模块
from pygame.locals import *

#导入我方飞机模块
import myplane
#导入敌方飞机模块
import enemy
#导入子弹模块
import bullet
# 导入补给包模块
import supply
import random

pygame.init()
pygame.mixer.init()

bg_size = width, height = 400, 700
screen = pygame.display.set_mode(bg_size)
pygame.display.set_caption("飞机大战 -- 开炮")

#载入背景图片
background = pygame.image.load("g:/Py_Self/plane/images/background.png").convert_alpha()

# rgb  三原色 白色 (255,255,255)
WHITE = (255,255,255)
BLACK = (0,0,0)
GREEN = (0,255,0)
RED = (255,0,0)


# 载入游戏音乐
pygame.mixer.music.load("g:/Py_Self/plane/sound/game_music.ogg")
pygame.mixer.music.set_volume(0.2)
bullet_sound = pygame.mixer.Sound("g:/Py_Self/plane/sound/bullet.wav")
bullet_sound.set_volume(0.2)
bomb_sound = pygame.mixer.Sound("g:/Py_Self/plane/sound/use_bomb.wav")
bomb_sound.set_volume(0.2)
supply_sound = pygame.mixer.Sound("g:/Py_Self/plane/sound/supply.wav")
supply_sound.set_volume(0.2)
get_bomb_sound = pygame.mixer.Sound("g:/Py_Self/plane/sound/get_bomb.wav")
get_bomb_sound.set_volume(0.2)
get_bullet_sound = pygame.mixer.Sound("g:/Py_Self/plane/sound/get_bullet.wav")
get_bullet_sound.set_volume(0.2)
upgrade_sound = pygame.mixer.Sound("g:/Py_Self/plane/sound/upgrade.wav")
upgrade_sound.set_volume(0.2)
enemy3_fly_sound = pygame.mixer.Sound("g:/Py_Self/plane/sound/enemy3_flying.wav")
enemy3_fly_sound.set_volume(0.2)
enemy1_down_sound = pygame.mixer.Sound("g:/Py_Self/plane/sound/enemy1_down.wav")
enemy1_down_sound.set_volume(0.2)
enemy2_down_sound = pygame.mixer.Sound("g:/Py_Self/plane/sound/enemy2_down.wav")
enemy2_down_sound.set_volume(0.2)
enemy3_down_sound = pygame.mixer.Sound("g:/Py_Self/plane/sound/enemy3_down.wav")
enemy3_down_sound.set_volume(0.5)
me_down_sound = pygame.mixer.Sound("g:/Py_Self/plane/sound/me_down.wav")
me_down_sound.set_volume(0.2)



def add_small_enemies(group1,group2,num):
    for i in range(num):
        e1 = enemy.SmallEnemy(bg_size)
        group1.add(e1)
        group2.add(e1)
def add_mid_enemies(group1,group2,num):
    for i in range(num):
        e2 = enemy.MidEnemy(bg_size)
        group1.add(e2)
        group2.add(e2)
def add_big_enemies(group1,group2,num):
    for i in range(num):
        e3 = enemy.BigEnemy(bg_size)
        group1.add(e3)
        group2.add(e3)


def inc_speed(target,inc):
    for each in target:
        each.speed += inc

def main():
    pygame.mixer.music.play(-1)
    #生成我方飞机
    me = myplane.MyPlane(bg_size)

    # 
    enemies = pygame.sprite.Group()


    #生成敌方小飞机
    small_enemies = pygame.sprite.Group()
    add_small_enemies(small_enemies,enemies,15)
    
    #生成敌方中型飞机
    mid_enemies = pygame.sprite.Group()
    add_mid_enemies(mid_enemies,enemies,4)

    #生成敌方大型飞机
    big_enemies = pygame.sprite.Group()
    add_big_enemies(big_enemies,enemies,2)
    clock = pygame.time.Clock()

    # 生成普通子弹
    bullet1 = []
    bullet1_index = 0
    BULLET1_NUM = 4

    for i in range(BULLET1_NUM):
        bullet1.append(bullet.Bullet1(me.rect.midtop))
    # 生成超级子弹
    bullet2 = []
    bullet2_index = 0
    BULLET2_NUM = 8 #发射8发子弹  因为是双枪 所以 要地板除 2

    for i in range(BULLET2_NUM // 2):
        bullet2.append(bullet.Bullet2((me.rect.centerx -33,me.rect.centery)))   
        bullet2.append(bullet.Bullet2((me.rect.centerx +30,me.rect.centery)))

    
    ## 中弹 图像索引
    e1_destroy_index = 0
    e2_destroy_index = 0
    e3_destroy_index = 0
    me_destroy_index = 0

    # 统计得分
    score = 0
    #指定得分字体
    score_font = pygame.font.Font("g:/Py_Self/plane/font/font.ttf",36)
    #标志是否暂停游戏
    paused = False
    pause_nor_image = pygame.image.load("g:/Py_Self/plane/images/pause_nor.png").convert_alpha()
    pause_pressed_image = pygame.image.load("g:/Py_Self/plane/images/pause_pressed.png").convert_alpha()
    #标志是否开始游戏
    resume_nor_image = pygame.image.load("g:/Py_Self/plane/images/resume_nor.png").convert_alpha()
    resume_pressed_image = pygame.image.load("g:/Py_Self/plane/images/resume_pressed.png").convert_alpha()
    paused_rect = pause_nor_image.get_rect()
    paused_rect.left,paused_rect.top = width -paused_rect.width -10,10
    paused_image = pause_nor_image

    # 设置难度级别
    level = 1
    # 全屏炸弹  放大招 每款游戏都有一个大决 瞬间KO
    bomb_image = pygame.image.load("g:/Py_Self/plane/images/bomb.png").convert_alpha()
    bomb_rect = bomb_image.get_rect()
    bomb_font = pygame.font.Font("/Py_Self/plane/font/font.ttf",48)
    bomb_num = 3

    #每30秒发放一个补给包
    bullet_supply = supply.Bullet_Supply(bg_size)
    bomb_supply = supply.Bomb_Supply(bg_size)
    #设置定时器
    SUPPLY_TIME = USEREVENT
    pygame.time.set_timer(SUPPLY_TIME,30 *1000)
    #超级子弹定时器
    DOUBLE_BULLET_TIME = USEREVENT + 1

    #标志是否使用超级子弹
    is_double_bullet = False

    # 解除我方无敌状态定时器
    INVINCIBLE_TIME = USEREVENT + 2
    
    #生命数量
    life_image = pygame.image.load("g:/Py_Self/plane/images/life.png").convert_alpha()
    life_rect = life_image.get_rect()
    #初始化角色有三条命
    life_num =3

    #游戏结束画面
    gameover_font = pygame.font.Font("g:/Py_Self/plane/font/font.ttf", 48)
    again_image = pygame.image.load("g:/Py_Self/plane/images/again.png").convert_alpha()
    again_rect = again_image.get_rect()
    gameover_image = pygame.image.load("g:/Py_Self/plane/images/gameover.png").convert_alpha()
    gameover_rect = gameover_image.get_rect()

    # 用于阻止重复打开记录文件
    recorded = False
    
    # 用于切换图片
    switch_image = True
    #用于延迟
    delay = 100
    
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.quit()
                sys.exit()
                
            elif event.type == MOUSEBUTTONDOWN:
                if event.button == 1 and paused_rect.collidepoint(event.pos):
                    paused = not paused
                    ## 按下暂停键的话 就 暂停事件 音效 补给包
                    if paused:
                        pygame.time.set_timer(SUPPLY_TIME,0)
                        pygame.mixer.music.pause()
                        pygame.mixer.pause()
                    else:
                        pygame.time.set_timer(SUPPLY_TIME,30*1000)
                        pygame.mixer.music.unpause()
                        pygame.mixer.unpause()
                        
                    
            elif event.type == MOUSEMOTION:
                if paused_rect.collidepoint(event.pos):     
                    if paused:
                        paused_image = resume_pressed_image
                    else:
                        paused_image = pause_pressed_image
                else:
                    if paused:
                        paused_image = resume_nor_image
                    else:
                        paused_image = pause_nor_image
                        
            elif event.type == KEYDOWN:
                if event.key == K_SPACE:
                    if bomb_num:
                        bomb_num -= 1
                        bomb_sound.play()
                        for each in enemies:
                            if each.rect.bottom > 0:
                                each.active = False
            elif event.type == SUPPLY_TIME:
                supply_sound.play()
                if random.choice([True,False]):
                    bomb_supply.reset()
                else:
                    bullet_supply.reset()
            elif event.type == DOUBLE_BULLET_TIME:
                is_double_bullet = False
                #关闭定时器
                pygame.time.set_timer(DOUBLE_BULLET_TIME,0)
            elif event.type == INVINCIBLE_TIME:
                me.invincible = False
                pygame.time.set_timer(INVINCIBLE_TIME,0)
                
                            
        # 根据用户的得分增加难度
        if level == 1 and score > 50000:
            level = 2
            upgrade_sound.play()
            #增加3架小型敌机, 2架中型敌机和1驾大型敌机
            add_small_enemies(small_enemies,enemies,3)
            add_mid_enemies(mid_enemies,enemies,2)
            add_big_enemies(big_enemies,enemies,1)
            #提升小型敌机的速度
            inc_speed(small_enemies,1)
        elif level == 2 and score > 300000:
            level = 3
            upgrade_sound.play()
            #增加5架小型敌机, 3架中型敌机和2驾大型敌机
            add_small_enemies(small_enemies,enemies,5)
            add_mid_enemies(mid_enemies,enemies,3)
            add_big_enemies(big_enemies,enemies,2)
            #提升小型敌机的速度
            inc_speed(small_enemies,1)
            inc_speed(mid_enemies,1)
        elif level == 3 and score > 600000:
            level = 4
            upgrade_sound.play()
            #增加5架小型敌机, 3架中型敌机和2驾大型敌机
            add_small_enemies(small_enemies,enemies,5)
            add_mid_enemies(mid_enemies,enemies,3)
            add_big_enemies(big_enemies,enemies,2)
            #提升小型敌机的速度
            inc_speed(small_enemies,1)
            inc_speed(mid_enemies,1)
        elif level == 4 and score > 1000000:
            level = 5
            upgrade_sound.play()
            #增加5架小型敌机, 3架中型敌机和2驾大型敌机
            add_small_enemies(small_enemies,enemies,5)
            add_mid_enemies(mid_enemies,enemies,3)
            add_big_enemies(big_enemies,enemies,2)
            #提升小型敌机的速度
            inc_speed(small_enemies,1)
            inc_speed(mid_enemies,1)
            
        #背景图片
        screen.blit(background,(0,0))                
        if life_num and not paused:
            # 检测用户的键盘操作
            key_pressed = pygame.key.get_pressed()

            if key_pressed[K_w] or key_pressed[K_UP]:
                me.moveUp()
            if key_pressed[K_s] or key_pressed[K_DOWN]:
                me.moveDown()
            if key_pressed[K_a] or key_pressed[K_LEFT]:
                me.moveLeft()
            if key_pressed[K_d] or key_pressed[K_RIGHT]:
                me.moveRight()
            # 绘制全屏炸弹补给并检测是否获得
            if bomb_supply.active:
                bomb_supply.move()
                screen.blit(bomb_supply.image,bomb_supply.rect)
                if pygame.sprite.collide_mask(bomb_supply,me):
                     get_bomb_sound.play()
                     if bomb_num < 3:
                         bomb_num +=1
                         bomb_supply.active = False
            # 绘制超级子弹补给并检测是否获得
            if bullet_supply.active:
                bullet_supply.move()
                screen.blit(bullet_supply.image,bullet_supply.rect)
                if pygame.sprite.collide_mask(bullet_supply,me):
                     get_bullet_sound.play()
                     #发射超级子弹
                     is_double_bullet = True
                     pygame.time.set_timer(DOUBLE_BULLET_TIME,18*1000)
                     bullet_supply.active = False         
            
            # 发射子弹
            #每10 帧发射一次子弹
            if not (delay % 10):
                bullet_sound.play()
                if is_double_bullet:
                    bullets = bullet2
                    bullets[bullet2_index].reset((me.rect.centerx -33,me.rect.centery))
                    bullets[bullet2_index+1].reset((me.rect.centerx +30,me.rect.centery))
                    bullet2_index = (bullet2_index+2) % BULLET2_NUM

                else:
                    bullets = bullet1
                    bullets[bullet1_index].reset(me.rect.midtop)
                    bullet1_index = (bullet1_index + 1) % BULLET1_NUM

            # 检测子弹是否击中敌机
            for b in bullets:
                if b.active:
                    b.move()
                    screen.blit(b.image,b.rect)
                    enemy_hit = pygame.sprite.spritecollide(b,enemies,False,pygame.sprite.collide_mask)
                    # 有数据 说明敌机中弹了
                    if enemy_hit:
                        b.active = False
                        for e in enemy_hit:
                            # 中型机 大型机 有血槽 
                            if e in mid_enemies or e in big_enemies :
                                e.hit = True
                                e.energy -= 1
                                if e.energy  == 0:
                                    e.active = False
                            else:
                                # 小型机一次就可以被秒了
                                e.active = False
                                    
                            
                
                
            
            # 绘制大型敌机
            # 绘制飞机前 要进行检查飞机的状态
            for each in big_enemies:
                if each.active:
                    each.move()
                    if each.hit:
                        # 绘制被打到的特效
                        screen.blit(each.image_hit,each.rect)
                        each.hit = False
                    else:
                        if switch_image:
                            screen.blit(each.image1,each.rect)
                        else:
                            screen.blit(each.image2,each.rect)

                    # 绘制血槽
                    pygame.draw.line(screen,BLACK,\
                                     (each.rect.left,each.rect.top -5),\
                                     (each.rect.right,each.rect.top -5),\
                                     2)
                    #当生命大于20% 显示绿色 否则显示红色  快挂了
                    # 当前的能量除以定义的能量  
                    energy_remain = each.energy / enemy.BigEnemy.energy
                    if energy_remain > 0.2:
                        energy_color = GREEN
                    else:
                        energy_color = RED
                    pygame.draw.line(screen,energy_color,\
                                     (each.rect.left,each.rect.top -5),\
                                     (each.rect.left +each.rect.width*energy_remain,\
                                      each.rect.top -5),\
                                     2)#2个像素
                     # 即将出现在画面中播放音效  出来一点就播放音效
                    if each.rect.bottom == -50:
                        enemy3_fly_sound.play(-1)
                else:
                    # 飞机被毁灭了 播放炸毁音效
                    #enemy3_down_sound.play()
                    if not(delay % 3):
                        if e3_destroy_index == 0:
                            enemy3_down_sound.play()
                        screen.blit(each.destroy_images[e3_destroy_index],each.rect)
                        # 索引加1 模 6  取到的索引是 0 - 5
                        e3_destroy_index = (e3_destroy_index+1) % 6
                        if e3_destroy_index == 0:
                            enemy3_fly_sound.stop() 
                            score += 10000
                            each.reset()
                            
                    
                    
           # 绘制中型机          
            for each in  mid_enemies:
                if each.active:
                    each.move()
                    if each.hit:
                        # 绘制被打到的特效
                        screen.blit(each.image_hit,each.rect)
                        each.hit = False
                    else:
                        screen.blit(each.image,each.rect)
                    # 绘制血槽
                    pygame.draw.line(screen,BLACK,\
                                     (each.rect.left,each.rect.top -5),\
                                     (each.rect.right,each.rect.top -5),\
                                     2)
                    #当生命大于20% 显示绿色 否则显示红色  快挂了
                    energy_remain = each.energy / enemy.MidEnemy.energy
                    if energy_remain > 0.2:
                        energy_color = GREEN
                    else:
                        energy_color = RED
                    pygame.draw.line(screen,energy_color,\
                                     (each.rect.left,each.rect.top -5),\
                                     (each.rect.left +each.rect.width*energy_remain,\
                                      each.rect.top -5),\
                                     2)#2个像素
                else:
                    # 飞机被毁灭了 播放炸毁音效
                    #enemy2_down_sound.play()
                    if not(delay % 3):
                        if e2_destroy_index == 0:
                            enemy2_down_sound.play()
                        screen.blit(each.destroy_images[e2_destroy_index],each.rect)
                        # 索引加1 模 4 取到的索引是 0 - 3
                        e2_destroy_index = (e2_destroy_index+1) % 4
                        if e2_destroy_index == 0:
                            score += 6000
                            each.reset()
                    
            # 绘制小型机
            for each in small_enemies:
                if each.active:
                    each.move()
                    screen.blit(each.image,each.rect)
                else:
                    # 飞机被毁灭了 播放炸毁音效
                    #enemy1_down_sound.play()
                    if not(delay % 3):
                        if e1_destroy_index == 0:
                            enemy1_down_sound.play()
                        screen.blit(each.destroy_images[e1_destroy_index],each.rect)
                        # 索引加1 模 4 取到的索引是 0 - 3
                        e1_destroy_index = (e1_destroy_index+1) % 4
                        if e1_destroy_index == 0:
                            score += 1000
                            each.reset()

                            
            # 检测我方飞机是否被撞
            enemies_down = pygame.sprite.spritecollide(me,enemies,False,pygame.sprite.collide_mask)
            if enemies_down and not me.invincible:
                me.active = False
                for e in enemies_down:
                    e.active = False
                
            #绘制我方飞机
            if me.active:   
                switch_image = not switch_image
                if switch_image:
                    screen.blit(me.image1,me.rect)
                else:
                    screen.blit(me.image2,me.rect)
            else:
                # 我方飞机被毁灭了 播放炸毁音效
                #me_down_sound.play()
                if not(delay % 3):
                    if me_destroy_index == 0:
                        me_down_sound.play()
                    screen.blit(me.destroy_images[me_destroy_index],me.rect)
                    # 索引加1 模 4 取到的索引是 0 - 3
                    me_destroy_index = (me_destroy_index+1) % 4
                    if me_destroy_index == 0:
                        life_num -= 1
                        me.reset()
                        pygame.time.set_timer(INVINCIBLE_TIME,3*1000)
                        
            #绘制剩余全屏炸但数量  大招数量
            bomb_text = bomb_font.render("x %d" % bomb_num,True,WHITE)
            text_rect = bomb_text.get_rect()
            screen.blit(bomb_image,(10,height -10 -bomb_rect.height))
            screen.blit(bomb_text,(20+bomb_rect.width,height -5 -text_rect.height))

            
            #绘制剩余生命数量
            if life_num:
                for i in range(life_num):
                    screen.blit(life_image,\
                            (width-10-(i+1)*life_rect.width,\
                             height -10- life_rect.height))
            #绘制得分    
            score_text = score_font.render("Score : %s" % str(score),True,WHITE)             
            screen.blit(score_text,(10,5))
        #绘制游戏结束画面
        elif life_num == 0:
            # print("GAME_OVER")  游戏结束 1 背景音乐停止 补给包定时器停止
            # 背景音乐停止
            pygame.mixer.music.stop()


            #停止全部音效
            pygame.mixer.stop()

            #停止发放补给
            pygame.time.set_timer(SUPPLY_TIME,0)


            if not recorded:
                recorded = True
                #读取历史最高得分
                with open("g:/Py_Self/play_game/record.txt","r") as f:
                    record_score = int(f.read())             
                #如果玩家得分高于历史最高得分则存档
                if score > record_score:
                    with open("g:/Py_Self/play_game/record.txt","w") as f:
                        f.write(str(score))
            #绘制结束画面               
            record_score_text = score_font.render("Score : %s" % str(score),True,WHITE)
            record_score_text = score_font.render("Best: %d" % record_score,True,WHITE)
            screen.blit(record_score_text, (50,50))
            
            gameover_text1 = gameover_font.render("Your Score: ", True, WHITE)
            gameover_text1_rect = gameover_text1.get_rect()
            gameover_text1_rect.left, gameover_text1_rect.top = \
                                (width - gameover_text1_rect.width) // 2, height // 2
            screen.blit(gameover_text1, gameover_text1_rect)

            
            gameover_text2 = gameover_font.render(str(score), True, WHITE)
            gameover_text2_rect = gameover_text2.get_rect()
            gameover_text2_rect.left, gameover_text2_rect.top = \
                                (width - gameover_text2_rect.width) // 2, \
                                gameover_text1_rect.bottom + 10
            screen.blit(gameover_text2, gameover_text2_rect)

            again_rect.left, again_rect.top = \
                        (width - again_rect.width) // 2,\
                        gameover_text2_rect.bottom + 50
            screen.blit(again_image, again_rect)

            gameover_rect.left, gameover_rect.top = \
                        (width - again_rect.width) // 2, \
                        again_rect.bottom + 10
            screen.blit(gameover_image, gameover_rect)

            # 检测用户的鼠标操作
            # 如果用户按下鼠标左键
            if pygame.mouse.get_pressed()[0]:
                pos = pygame.mouse.get_pos()
                if again_rect.left < pos[0] < again_rect.right and \
                   again_rect.top < pos[1] < again_rect.bottom:
                    main()
                elif gameover_rect.left < pos[0] < gameover_rect.right and \
                     gameover_rect.top < pos[1] < gameover_rect.bottom:
                     pygame.quit()
                     sys.exit()
            
                               
                                
            
            
        
        # 绘制暂停按钮
        screen.blit(paused_image,paused_rect)
            
        # 切换图片  只有被5 整除才会切换图片 也就是 5 帧切换一次 
        if not(delay%5):
            switch_image = not switch_image
        ## 在每一帧中 delay -1
        delay -= 1
        if not delay:
            delay = 100
        pygame.display.flip()
        clock.tick(60)

if __name__ =="__main__":
    try:
        main()
    except SystemExit:
        pass
    except:
        traceback.print_exc()
        pygame.quit()
        input()
        
        
