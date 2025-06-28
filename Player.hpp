#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "BowlingGame.hpp"

class Player {
public:
    Player(std::string playerName);

    void playFrame(int r1, int r2 = 0, int r3 = 0);
    int getScore() const;
    std::string getName();

private:
    std::string name;
    BowlingGame game;
};

#endif
