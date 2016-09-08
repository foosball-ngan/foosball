#ifndef Game_h
#define Game_h

#include <inttypes.h>

#define MAX_SCORE 10

class Game {
  public:
    Game();
    bool hasWinner();
    void resetScores();
    void increasePlayer1Score();
    void decreasePlayer1Score();
    void increasePlayer2Score();
    void decreasePlayer2Score();
    
  private:
    uint8_t _p1_score;
    uint8_t _p2_score;
};

#endif

