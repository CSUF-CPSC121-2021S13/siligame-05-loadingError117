#ifndef OPPONENT_H
#define OPPONENT_H

#include <iostream>

#include "cpputils/graphics/image.h"
#include "game_element.h"

/*
Opponent Sprite
*/

class OpponentProjectile : public GameElement {
 public:
  // Default Constructor
  OpponentProjectile() : GameElement(0, 0, 5, 5) {}
  // Constructor
  OpponentProjectile(int x, int y) : GameElement(x, y, 5, 5) {}

  // Draws a Opponent Projectile at the location
  void Draw(graphics::Image& background) override;

  // Moves the images across the screen
  void Move(const graphics::Image& background) override;
};

class Opponent : public GameElement {
 private:
  const int kwidth_ = 50;
  const int kheight_ = 50;
  int counter_ = 0;

 public:
  // Default Constructor
  Opponent() : GameElement(0, 0, 50, 50) {}
  // Constructor
  Opponent(int x, int y) : GameElement(x, y, 50, 50) {}

  // Draws the Opponent at the location
  void Draw(graphics::Image& background) override;

  // Moves the images across the screen
  void Move(const graphics::Image& background) override;

  // Fires an Opponent Projectile
  std::unique_ptr<OpponentProjectile> LaunchProjectile();
};

#endif  // OPPONENT_H