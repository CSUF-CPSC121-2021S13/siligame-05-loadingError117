#include "game.h"

// Game Class
// Creates Opponents and adds them to the opponents_ vector
void Game::CreateOpponents() {
  opponents_.push_back(std::make_unique<Opponent>(50, 80));
}

// Game Class
// Changes the position of Player
void Game::Init() {
  background_.AddMouseEventListener(*this);
  background_.AddAnimationEventListener(*this);
  player_.GameElement::SetX(player_.GameElement::GetX() + 2);
  player_.GameElement::SetY(player_.GameElement::GetY() + 2);
}

// Game Class
// Starts the game
void Game::Start() { background_.ShowUntilClosed(); }

// Game Class
// Moves all elements in the game
void Game::MoveGameElements() {
  for (int i = 0; i < opponents_.size(); i++) {
    if (opponents_[i]->GetIsActive() == true) {
      opponents_[i]->Move(background_);
    }
  }
  for (int i = 0; i < pProjectiles_.size(); i++) {
    if (pProjectiles_[i]->GetIsActive() == true) {
      pProjectiles_[i]->Move(background_);
    }
  }
  for (int i = 0; i < opProjectiles_.size(); i++) {
    if (opProjectiles_[i]->GetIsActive() == true) {
      opProjectiles_[i]->Move(background_);
    }
  }
}

// Game Class
// Deactivates objects that have collided
void Game::FilterIntersections() {
  for (int i = 0; i < opProjectiles_.size(); i++) {
    if (player_.IntersectsWith(opProjectiles_[i].get())) {
      player_.SetIsActive(false);
      opProjectiles_[i]->SetIsActive(false);
      HasLost_ = true;
    }
  }
  for (int i = 0; i < opponents_.size(); i++) {
    if (player_.IntersectsWith(opponents_[i].get())) {
      player_.SetIsActive(false);
      opponents_[i]->SetIsActive(false);
      HasLost_ = true;
    }
  }
  for (int i = 0; i < pProjectiles_.size(); i++) {
    for (int j = 0; j < opponents_.size(); j++) {
      if (opponents_[j]->IntersectsWith(pProjectiles_[i].get())) {
        pProjectiles_[i]->SetIsActive(false);
        opponents_[j]->SetIsActive(false);
        if (player_.GetIsActive() == true) {
          score_++;
        }
      }
    }
  }
}

// Wipes the screen of all entities
void Game::UpdateScreen() {
  background_.DrawRectangle(0, 0, background_.GetWidth(),
                            background_.GetHeight(), 255, 255, 255);
  background_.DrawText(0, 0, "Score: " + std::to_string(score_), 5, 0, 0, 0);
  if (player_.GetIsActive() == true) {
    player_.Draw(background_);
  }
  for (int i = 0; i < opponents_.size(); i++) {
    if (opponents_[i]->GetIsActive() == true) {
      opponents_[i]->Draw(background_);
    }
  }
  for (int i = 0; i < opProjectiles_.size(); i++) {
    if (opProjectiles_[i]->GetIsActive() == true) {
      opProjectiles_[i]->Draw(background_);
    }
  }
  for (int i = 0; i < pProjectiles_.size(); i++) {
    if (pProjectiles_[i]->GetIsActive() == true) {
      pProjectiles_[i]->Draw(background_);
    }
  }
  if (HasLost_ == false) {
    background_.DrawText(5, 250, "YOU DIED", 25, 0, 0, 0);
  }
}

// Game Class
// Refreshes the Screen
void Game::OnAnimationStep() {
  if (opponents_.size() == 0) {
    CreateOpponents();
  }
  MoveGameElements();
  LaunchProjectiles();
  FilterIntersections();
  RemoveInactive();
  UpdateScreen();
  background_.Flush();
}

// Game Class
// Controls the player object
void Game::OnMouseEvent(const graphics::MouseEvent& event) {
  if (event.GetX() >= 0 && event.GetY() >= 0 &&
      event.GetY() <= background_.GetHeight() &&
      event.GetX() <= background_.GetWidth()) {
    player_.SetX(event.GetX() - (player_.GetWidth() / 2));
    player_.SetY(event.GetY() - (player_.GetHeight() / 2));
  }
  if (event.GetMouseAction() == graphics::MouseAction::kPressed ||
      event.GetMouseAction() == graphics::MouseAction::kDragged) {
    pProjectiles_.push_back(std::make_unique<PlayerProjectile>(
        player_.GetX() + (player_.GetWidth() / 2) + 5, player_.GetY()));
  }
}

// Game Class
// Launches all the opponent's projectiles
void Game::LaunchProjectiles() {
  for (int i = 0; i < opponents_.size(); i++) {
    std::unique_ptr<OpponentProjectile> newOP =
        std::make_unique<OpponentProjectile>(opponents_[i]->GetX(),
                                             opponents_[i]->GetY());
    if (opponents_[i]->LaunchProjectile() != nullptr) {
      opProjectiles_.push_back(std::move(newOP));
    }
  }
}

// Removes any inactive functions
void Game::RemoveInactive() {
  for (int i = 0; i < opponents_.size(); i++) {
    if (opponents_[i]->GetIsActive() == false) {
      opponents_.erase(opponents_.begin() + i);
      i--;
    }
  }
  for (int i = 0; i < opProjectiles_.size(); i++) {
    if (opProjectiles_[i]->GetIsActive() == false) {
      opProjectiles_.erase(opProjectiles_.begin() + i);
      i--;
    }
  }
  for (int i = 0; i < pProjectiles_.size(); i++) {
    if (pProjectiles_[i]->GetIsActive() == false) {
      pProjectiles_.erase(pProjectiles_.begin() + i);
      i--;
    }
  }
}