#include <iostream>
#include "yahtzee/yahtzee.h"

int main()
{
    // Header
    std::cout << "Yathzee - Created in C++"
              << std::endl
              << std::endl;

    // Class for the game
    yahtzee::Yahtzee game;

    // Ask the user for the names of the players
    // Counter for the users
    uint16_t player_id = 0;
    while (true)
    {
        // Ask the user for the name of the player
        std::cout << "Player " << ++player_id << " name [empty to stop]: ";
        std::string name = "";
        std::getline(std::cin, name);

        // Empty name, stop the loop!
        if (name.length() == 0)
            break;

        // Add the new player to the list
        game.add_player(name);
    }

    return 0;
}