#include "opponent.h"

// Opponent Class
// Draws the Opponent at the location
void Opponent::Draw(graphics::Image& background) {
  // Color(s)
  const graphics::Color black(0, 0, 0);
  const graphics::Color grey(124, 129, 125);

  graphics::Image OpponentSprite(50, 50);
  OpponentSprite.DrawRectangle(0, 0, 50, 25, black);  // Base Body
  OpponentSprite.DrawLine(35, 0, 35, 25, grey, 2);
  OpponentSprite.DrawLine(15, 0, 15, 25, grey, 2);
  OpponentSprite.DrawRectangle(20, 25, 10, 15, black);  // Lower Barrel
  OpponentSprite.DrawRectangle(22, 40, 6, 10, black);   // Upper Barrel
  Position(background, OpponentSprite, GetX(), GetY());
}

// Opponent Class
// Moves the images accross the screen
void Opponent::Move(const graphics::Image& background) {
  x_ += 10;
  y_ += 2;
  if (IsOutOfBounds(background)) {
    is_active_ = false;
  }
}

// Opponent Class
// Fires an Opponent Projectile
std::unique_ptr<OpponentProjectile> Opponent::LaunchProjectile() {
  counter_++;
  if (counter_ - 1 != 10) {
    return nullptr;
  } else {
    counter_ = 0;
    return std::make_unique<OpponentProjectile>(x_ + (kwidth_ / 2) - 5,
                                                kheight_);
  }
}

// OpponentProjectile Class
// Draws a Opponent Projectile at the location
void OpponentProjectile::Draw(graphics::Image& background) {
  // Color(s)
  const graphics::Color green(6, 242, 52);

  graphics::Image opponentProjectile(5, 5);
  opponentProjectile.DrawRectangle(0, 0, 5, 5, green);
  Position(background, opponentProjectile, GetX(), GetY());
}

// OpponentProjectile Class
// Moves the images accross the screen
void OpponentProjectile::Move(const graphics::Image& background) {
  y_ += 5;
  if (IsOutOfBounds(background)) {
    is_active_ = false;
  }
}