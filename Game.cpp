#include "Game.h"
#include <Arduino.h>

Game::Game() {
  this->resetScores();
}

bool Game::hasWinner(void) {
  return (_p1_score == MAX_SCORE || _p2_score == MAX_SCORE);
}

void Game::resetScores(void) {
  _p1_score = 0;
  _p2_score = 0;
}

void Game::increasePlayer1Score(void) {
  _p1_score = (_p1_score == MAX_SCORE) ? 0 : _p1_score + 1;
}

void Game::decreasePlayer1Score(void) {
  _p1_score = (_p1_score == 0) ? MAX_SCORE : _p1_score - 1;
}

void Game::increasePlayer2Score(void) {
  _p2_score = (_p2_score == MAX_SCORE) ? 0 : _p2_score + 1;
}

void Game::decreasePlayer2Score(void) {
  _p2_score = (_p2_score == 0) ? MAX_SCORE : _p2_score - 1;
}
