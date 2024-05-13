# Moving platform
# Game object for player to interact with (jump boost, speed boost, zero or low gravity, more gravity - enemy object)
# enhancement on specific levels (double jump)
# types of platform (trampoline, ghost [multiple types dependent on re-appearing time], ice)
# Environment hazards (Wind)
# Scenery changes per chunks of levels

#Debug trampoline only bounces once

import pygame
import sys
from pygame.locals import *

# Initialize pygame
pygame.init()

# Constants
WIDTH = 800
HEIGHT = 600

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
BLUE = (0, 0, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
YELLOW = (255, 255, 0)
CYAN = (0, 255, 255)
ICE_BLUE = (173, 216, 230)
TRAMPOLINE_GREEN = (124, 252, 0)
GREY = (101, 102, 109)


class Player(pygame.sprite.Sprite):

  def __init__(self):
    super().__init__()
    self.surf = pygame.Surface((50, 25))
    self.surf.fill(RED)
    self.rect = self.surf.get_rect(center=(100, 100))
    self.vel_y = 0
    self.jumping = False
    self.jump_boost = False
    self.speed_boost = False
    self.max_gravity = False

    self.ability_timers = {"jump_boost": 0, "speed_boost": 0, "max_gravity": 0}

  def update(self, platforms):
    keys = pygame.key.get_pressed()

    move_speed = 20 if self.speed_boost else 5

    if keys[pygame.K_a]:
      self.rect.move_ip(-move_speed, 0)
      self.collide_with_platforms(platforms, 0, -move_speed)
    if keys[pygame.K_d]:
      self.rect.move_ip(move_speed, 0)
      self.collide_with_platforms(platforms, 0, move_speed)

    # Gravity
    gravity = 0.2 if self.max_gravity else 0.5
    self.vel_y += gravity
    self.rect.move_ip(0, self.vel_y)
    self.collide_with_platforms(platforms, self.vel_y, 0)

    if self.rect.top > HEIGHT:
      print("Achievement - Escaped the confines of this reality")

    for ability in self.ability_timers:
      if self.ability_timers[ability] > 0:
        self.ability_timers[ability] -= 1
        if self.ability_timers[ability] == 0:
          setattr(self, ability, False)

  def collide_with_platforms(self, platforms, y_vel, x_vel):
    for platform in platforms:
      if pygame.sprite.collide_rect(self, platform):
        

        if y_vel > 0:  # Falling
          self.rect.bottom = platform.rect.top
          self.jumping = False
          self.vel_y = 0
        elif y_vel < 0:  # Moving upwards
          self.rect.top = platform.rect.bottom
          self.vel_y = 0
        if x_vel > 0:  # Moving right
          self.rect.right = platform.rect.left
        elif x_vel < 0:  # Moving left
          self.rect.left = platform.rect.right
          
        if isinstance(platform, IcePlatform):
          self.rect.move_ip(x_vel * 3.5, 0)
        if isinstance(platform, TrampolinePlatform):
          self.vel_y = -15
          self.jumping = True
          print("fuhawehihfiu")
        if isinstance(platform, GhostPlatform):
          platform.timer += 1
          

  def jump(self):
    if not self.jumping or self.jump_boost:
      if self.max_gravity:
        jump_strength = 5
      else:
        jump_strength = 26 if self.jump_boost else 15
      self.vel_y = -jump_strength
      self.jumping = True


class Platform(pygame.sprite.Sprite):

  def __init__(self, x, y, w, h):
    super().__init__()
    self.image = pygame.image.load('platform.png')
    self.surf = pygame.transform.scale(self.image, (w, h))
    self.rect = self.surf.get_rect(topleft=(x, y))


class MovingPlatform(Platform):

  def __init__(self, x, y, w, h, end_x, end_y, speed):
    super().__init__(x, y, w, h)
    self.start_x = x
    self.start_y = y
    self.end_x = end_x
    self.end_y = end_y
    self.speed = speed
    self.direction = 1  # 1 for moving towards the end, -1 for moving towards the start

  def update(self, *args):
    if self.direction == 1:
      if self.rect.x < self.end_x:
        self.rect.x += self.speed
      else:
        self.direction = -1
    else:
      if self.rect.x > self.start_x:
        self.rect.x -= self.speed
      else:
        self.direction = 1


class GhostPlatform(Platform):

  def __init__(self, x, y, w, h):
    super().__init__(x, y, w, h)
    self.timer = 0
    self.visible = True
    self.surf.fill(RED)

  def update(self, player):
    #self.surf.set_alpha(self.surf.get_alpha() - 1)
  #if pygame.sprite.collide_rect(self, player):
    #self.timer += 1
    print(self.timer)
    if self.timer >= 5 * 60:  # 5 seconds
      self.visible = False
      self.surf.set_alpha(0)
      pygame.time.set_timer(USEREVENT + 1, 1000)
        

      if not self.visible:
        self.rect.y += 10000

  def handle_reappear(self):
    self.visible = True
    self.surf.set_alpha(255)
    self.rect.y -= 10000


class IcePlatform(Platform):

  def __init__(self, x, y, w, h):
    super().__init__(x, y, w, h)
    self.surf.fill(ICE_BLUE)


class TrampolinePlatform(Platform):

  def __init__(self, x, y, w, h):
    super().__init__(x, y, w, h)
    self.surf.fill(TRAMPOLINE_GREEN)


class Collectable(pygame.sprite.Sprite):

  def __init__(self, x, y, width, height, color):
    super().__init__()
    self.surf = pygame.Surface((width, height))
    self.surf.fill(color)
    self.rect = self.surf.get_rect(topleft=(x, y))

  def apply_effect(self, player):
    pass

  def start_effect(self, player, effect_name):
    player.ability_timers[effect_name] = 3 * 60
    setattr(player, effect_name, True)


class JumpBoost(Collectable):

  def __init__(self, x, y):
    super().__init__(x, y, 20, 20, GREEN)

  def apply_effect(self, player):
    self.start_effect(player, "jump_boost")


class SpeedBoost(Collectable):

  def __init__(self, x, y):
    super().__init__(x, y, 20, 20, YELLOW)

  def apply_effect(self, player):
    self.start_effect(player, "speed_boost")


class MaxGravity(Collectable):

  def __init__(self, x, y):
    super().__init__(x, y, 20, 20, CYAN)

  def apply_effect(self, player):
    self.start_effect(player, "max_gravity")

class FinishLevel(Collectable):

  def __init__(self, x, y):
    super().__init__(x, y, 20, 20, BLACK)

  def apply_effect(self, player):
    self.start_effect(player, "end")
  


class Projectile(pygame.sprite.Sprite):

  def __init__(self, x, y, direction):
    super().__init__()
    self.image = pygame.image.load("bullet.png")
    self.surf = pygame.transform.scale(self.image, (25, 25))
    self.rect = self.surf.get_rect()
    self.rect.center = (x, y)
    self.speed = 5
    self.direction = direction

  def update(self):
    if self.direction == 'left':
      self.rect.x -= self.speed
    elif self.direction == "right":
      self.rect.x += self.speed

    if self.rect.right < 0 or self.rect.left > WIDTH:
      self.kill()


class Enemy(pygame.sprite.Sprite):

  def __init__(self, x, y, min_x, max_x):
    super().__init__()
    self.image = pygame.image.load("enemy.png")
    self.surf = pygame.transform.scale(self.image, (30,30))
    self.rect = self.surf.get_rect(topleft=(x,y))
    self.min_x = min_x
    self.max_x = max_x
    self.velocity = 2
    self.shoot_timer = 60
    self.player_last_x = x

  def update(self):
    self.shoot_timer -= 1

    if self.shoot_timer <= 0:
      projectile = Projectile(
        self.rect.centerx, self.rect.centery,
        "left" if self.rect.centerx > self.player_last_x else "right")
      projectiles.add(projectile)
      all_sprites.add(projectile)

      self.shoot_timer = 60

    self.rect.x += self.velocity
    if self.rect.x < self.min_x or self.rect.x >= self.max_x:
      self.velocity = -self.velocity

    self.player_last_x = player.rect.centerx


# Main game loop
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Basic Platformer")
clock = pygame.time.Clock()

player = Player()
all_sprites = pygame.sprite.Group(player)

platforms = pygame.sprite.Group()
collectables = pygame.sprite.Group()
enemies = pygame.sprite.Group()
projectiles = pygame.sprite.Group()

p1 = Platform(0, HEIGHT - 30, WIDTH, 30)
platforms.add(p1)
all_sprites.add(p1)

p2 = Platform(20, 0, 30, 600)
platforms.add(p2)
all_sprites.add(p2)

p3 = Platform(200, 0, 30, 500)
platforms.add(p3)
all_sprites.add(p3)

mp1 = MovingPlatform(300, 350, 150, 30, 500, 350, 3)
platforms.add(mp1)
all_sprites.add(mp1)

mp2 = MovingPlatform(300, 500, 150, 30, 350, 600, 3)
platforms.add(mp2)
all_sprites.add(mp2)

gp1 = GhostPlatform(200, 300, 110, 30)
platforms.add(gp1)
all_sprites.add(gp1)

tp1 = TrampolinePlatform(600, 300, 150, 30)
platforms.add(tp1)
all_sprites.add(tp1)

ip1 = IcePlatform(400, 100, 150, 30)
platforms.add(ip1)
all_sprites.add(ip1)

# Adding collectable to the game
collectables.add(JumpBoost(250, 200), SpeedBoost(400, 250),
                 MaxGravity(600, 200), FinishLevel(450, 15))
all_sprites.add(*collectables)

enemy1 = Enemy(400, 400, 300, 600)
enemies.add(enemy1)
enemy2 = Enemy(200, 150, 0, 900)
enemies.add(enemy2)
all_sprites.add(enemy1, enemy2)

while True:
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      pygame.quit()
    if event.type == pygame.KEYDOWN:
      if event.key == pygame.K_SPACE:
        player.jump()
    if event.type == USEREVENT + 1:
      for platform in platforms:
        if isinstance(platform, GhostPlatform):
          platform.handle_reappear()

  for platform in platforms:
    if isinstance(platform, (MovingPlatform, GhostPlatform)):
      platform.update(player)

  for collectable in collectables:
    if pygame.sprite.collide_rect(player, collectable):
      collectable.apply_effect(player)
      collectable.kill()

  for enemy in enemies:
    enemy.update()

  for projectile in projectiles:
    projectile.update()

    if pygame.sprite.collide_rect(player, projectile):
      print("Player hit by projectile")
      projectile.kill()
      #player.rect.x = 50
      #player.rect.y = 25
      collectables.add(JumpBoost(250, 200), SpeedBoost(400, 250),
                       MaxGravity(600, 200), FinishLevel(450, 15))
      all_sprites.add(*collectables)
      setattr(player, "jump_boost", False)
      setattr(player, "speed_boost", False)
      setattr(player, "max_gravity", False)

  screen.fill(WHITE)
  player.update(platforms)
  for object in all_sprites:
    screen.blit(object.surf, object.rect)

  pygame.display.flip()
  clock.tick(30)
