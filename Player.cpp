#include "Player.hpp"

Player::Player(std::string playerName) : name(playerName) {}

void Player::playFrame(int r1, int r2, int r3) {
    game.addFrame(Frame{r1, r2, r3});
}

int Player::getScore() const {
    return game.calculateScore();
}

std::string Player::getName() {
    return name;
}
