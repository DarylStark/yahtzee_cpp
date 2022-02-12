#include <iostream>
#include "yahtzee/player.h"

int main()
{
    std::cout << "Yathzee - Created in C++"
              << std::endl
              << std::endl;

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
        // TODO: implement
    }

    std::cout << "Added " << player_id << " players" << std::endl;

    return 0;
}