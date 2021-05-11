#include <iostream>

#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "opponent.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public GameElement {
 private:
  const int kWidth_ = 50;
  const int kHeight_ = 50;

 public:
  // Default Constructor
  Player() : GameElement() {}
  // Constructor
  Player(int x, int y) : GameElement(x, y, 50, 50) {}

  // Draws the Player at the location
  void Draw(graphics::Image& background) override;

  // Moves the Images across the screen
  void Move(const graphics::Image& background) override;
};

class PlayerProjectile : public GameElement {
 private:
  int kWidth_ = 5;
  int kHeight_ = 5;

 public:
  // Default Constructor
  PlayerProjectile() : GameElement() {}
  // Constructor
  PlayerProjectile(int x, int y) : GameElement(x, y, 5, 5) {}

  // Draws a Player Projectile at the location
  void Draw(graphics::Image& background) override;

  // Moves the Images across the screen
  void Move(const graphics::Image& background) override;
};

#endif  // PLAYER_H