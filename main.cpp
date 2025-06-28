#include <iostream>
#include <string>
#include "Player.hpp"

int getValidRoll(const std::string& prompt, int maxPins) {
    int roll;

    std::cout << prompt;
    std::cin >> roll;

    while (roll < 0 || roll > maxPins) {
        std::cout << "Invalid input. Enter a number between 0 and " << maxPins << ": ";
        std::cin >> roll;
    }

    return roll;
}

int main() {
    std::string name;
    std::cout << "Enter player name: ";
    std::getline(std::cin, name);

    Player player(name);
    std::cout << "Welcome, " << name << "! Let's start bowling.\n";

    for (int frame = 1; frame <= 10; ++frame) {
        std::cout << "\n--- Frame " << frame << " ---\n";

        int roll1 = getValidRoll("First roll: ", 10);
        int roll2 = 0, roll3 = 0;

        if (frame < 10) {
            // Normal frames (1 to 9)
            if (roll1 == 10) {
                std::cout << "Strike!\n";
                player.playFrame(roll1);
            } else {
                roll2 = getValidRoll("Second roll: ", 10 - roll1);
                if (roll1 + roll2 == 10) {
                    std::cout << "Spare!\n";
                }
                player.playFrame(roll1, roll2);
            }
        } else {
            // 10th frame
            roll2 = getValidRoll("Second roll: ", (roll1 == 10) ? 10 : 10 - roll1);

            if (roll1 == 10 || roll1 + roll2 == 10) {
                // Eligible for third roll
                roll3 = getValidRoll("Third roll: ", 10);
                player.playFrame(roll1, roll2, roll3);
            } else {
                player.playFrame(roll1, roll2);
            }
        }
    }

    std::cout << "\nGame Over! Final Score for " << player.getName() << ": " << player.getScore() << "\n";

    return 0;
}
