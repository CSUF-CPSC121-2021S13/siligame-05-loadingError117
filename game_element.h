#include "cpputils/graphics/image.h"

#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H

class GameElement {
 protected:
  int x_;
  int y_;
  int width_;
  int height_;
  bool is_active_ = true;

 public:
  // Default Constructor
  GameElement() : x_(0), y_(0), width_(50), height_(50) {}

  // Non-Default Constructor
  GameElement(int x, int y, int width, int height)
      : x_(x), y_(y), width_(width), height_(height) {}

  // Accessor for x_
  int GetX() const { return x_; }

  // Accessor for y_
  int GetY() const { return y_; }

  // Accessor for width_
  int GetWidth() const { return width_; }

  // Accessor for height_
  int GetHeight() const { return height_; }

  // Accessor for is_acitve_
  bool GetIsActive() const { return is_active_; }

  // Mutator for x_
  void SetX(int x) { x_ = x; }

  // Mutator for y_
  void SetY(int y) { y_ = y; }

  // Mutator for is_active_
  void SetIsActive(bool is_active) { is_active_ = is_active; }

  // Helper for Draw
  void Position(graphics::Image &background, graphics::Image &foreground,
                int x_, int y_);

  // Draws the images (pure virtual)
  virtual void Draw(graphics::Image &background) = 0;

  // Moves the images
  virtual void Move(const graphics::Image &background) = 0;

  // Checks to see if things intersects
  bool IntersectsWith(GameElement *collider);

  // Checks to see if images are out of bounds
  bool IsOutOfBounds(const graphics::Image &background);
};

#endif  // GAME_ELEMENT_H