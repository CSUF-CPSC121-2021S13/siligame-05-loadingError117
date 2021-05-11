#include "game_element.h"

// GameElement Class
// Draws the foreground image onto the background
void GameElement::Position(graphics::Image& background,
                           graphics::Image& foreground, int x_, int y_) {
  if (x_ <= background.GetWidth() && x_ >= 0 && y_ <= background.GetHeight() &&
      y_ >= 0) {
    for (int x = 0; x < foreground.GetWidth(); x++) {
      for (int y = 0; y < foreground.GetHeight(); y++) {
        background.SetColor(x + x_, y + y_, foreground.GetColor(x, y));
      }
    }
  }
}

// GameElement Class
// Checks to see if things intersects
bool GameElement::IntersectsWith(GameElement* collider) {
  return !(GetX() > collider->GetX() + collider->GetWidth() ||
           collider->GetX() > GetX() + GetWidth() ||
           GetY() > collider->GetY() + collider->GetHeight() ||
           collider->GetY() > GetY() + GetHeight());
}

// GameElement Class
// Checks to see if images are out of bounds
bool GameElement::IsOutOfBounds(const graphics::Image& background) {
  if (GetX() < 0 || GetX() + GetWidth() > background.GetWidth() || GetY() < 0 ||
      GetY() + GetHeight() > background.GetHeight()) {
    return true;
  } else {
    return false;
  }
}