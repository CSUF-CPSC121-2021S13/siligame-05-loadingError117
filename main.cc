#include <iostream>
#include <vector>

#include "cpputils/graphics/image.h"
#include "game.h"
#include "game_element.h"
#include "opponent.h"
#include "player.h"

int main() {
  Game currentGame;
  currentGame.Init();
  currentGame.Start();
  return 0;
}

/**
 * Start Siligame05 Game(game.h/game.cc) section
 **/