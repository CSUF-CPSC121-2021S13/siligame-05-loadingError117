#include "player.h"

#include "game_element.h"
#include "opponent.h"

// Player Class
// Draws the Player at the location
void Player::Draw(graphics::Image& background) {
  // Color(s)
  const graphics::Color blue(28, 95, 213);
  const graphics::Color black(0, 0, 0);

  graphics::Image PlayerSprite(50, 50);
  PlayerSprite.DrawRectangle(0, 25, 50, 25, blue);  // Base Rectangle
  PlayerSprite.DrawLine(35, 25, 35, 49, black, 2);
  PlayerSprite.DrawLine(15, 25, 15, 49, black, 2);
  PlayerSprite.DrawRectangle(20, 10, 10, 15, blue);  // Lower Barrel
  PlayerSprite.DrawRectangle(22, 0, 6, 10, blue);    // Upper Barrel
  Position(background, PlayerSprite, GetX(), GetY());
}

// Player Class
// Moves the images across the screen
void Player::Move(const graphics::Image& background) {
  /**
   * Needs Implementation (4/19/2021)
   **/
}

// PlayerProjectile Class
// Draws a Player Projectile at the location
void PlayerProjectile::Draw(graphics::Image& background) {
  // Color(s)
  const graphics::Color red(195, 11, 11);

  graphics::Image playerProjectile(5, 5);
  playerProjectile.DrawRectangle(0, 0, 5, 5, red);
  Position(background, playerProjectile, GetX(), GetY());
}

// PlayerProjectile Class
// Moves the images accross the screen
void PlayerProjectile::Move(const graphics::Image& background) {
  y_ += 5;
  if (IsOutOfBounds(background)) {
    is_active_ = false;
  }
}