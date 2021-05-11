#include <vector>

#include "cpputils/graphics/image.h"
#include "cpputils/graphics/image_event.h"
#include "game_element.h"
#include "opponent.h"
#include "player.h"

#ifndef GAME_H
#define GAME_H

class Game : public graphics::AnimationEventListener,
             public graphics::MouseEventListener {
 private:
  graphics::Image background_;
  std::vector<std::unique_ptr<Opponent>> opponents_;
  std::vector<std::unique_ptr<OpponentProjectile>> opProjectiles_;
  Player player_;
  std::vector<std::unique_ptr<PlayerProjectile>> pProjectiles_;
  int score_ = 0;
  bool HasLost_ = false;

 public:
  // Default constructor
  Game() : background_(800, 600) {}
  // Non-Default constructor
  Game(const int width, const int height) : background_(width, height) {}

  // Accessor for background_
  graphics::Image& GetGameScreen() { return background_; }

  // Accessor for opponents_
  std::vector<std::unique_ptr<Opponent>>& GetOpponents() { return opponents_; }

  // Accessor for opProjectiles_
  std::vector<std::unique_ptr<OpponentProjectile>>& GetOpponentProjectiles() {
    return opProjectiles_;
  }

  // Accessor for player_
  Player& GetPlayer() { return player_; }

  // Accessor for pProjectiles_
  std::vector<std::unique_ptr<PlayerProjectile>>& GetPlayerProjectiles() {
    return pProjectiles_;
  }

  // Creates Opponents and adds them to the opponents_ vector
  void CreateOpponents();

  // Creates Opponent Projectiles and adds them to the opProjectiles_ Vector
  void CreateOpponentProjectiles();

  // Creates Player Projectiles and adds them to the pProjectiles_ vector
  void CreatePlayerProjectiles();

  // Changes the position of Player
  void Init();

  // Starts the game
  void Start();

  // Moves all the elements in the game
  void MoveGameElements();

  // Deactivates objects that have collided
  void FilterIntersections();

  // Wipes the screen of all entities
  void UpdateScreen();

  // Refreshes the Screen
  void OnAnimationStep() override;

  // Controls the player object
  void OnMouseEvent(const graphics::MouseEvent& event) override;

  // Accessor for score_
  int GetScore() { return score_; }

  // Accessor HasLost_
  bool HasLost() { return HasLost_; }

  // Launches all the opponent's projectiles
  void LaunchProjectiles();

  // Removes any inactive functions
  void RemoveInactive();
};
#endif  // GAME_H