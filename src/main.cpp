#include <iostream>
#include "yahtzee/yahtzee.h"
#include "yahtzee/scorecard.h"
#include "yahtzee/dieset.h"

int main()
{
    using namespace yahtzee;
    ScoreCard scores;
    DieSet dies;

    dies.roll();

    uint16_t highest_index = 0;
    uint16_t highest_score = 0;
    for (int i = 0; i < 13; i++)
    {
        std::cout << scores[i].get_name() << " --> " << scores[i].get_points() << " --> " << scores[i].get_points_for_dieset(dies) << std::endl;
        if (scores[i].get_points_for_dieset(dies) > highest_score)
        {
            highest_score = scores[i].get_points_for_dieset(dies);
            highest_index = i;
        }
    }

    std::cout << std::endl
              << "Best option is " << scores[highest_index].get_name() << std::endl;

    return 0;

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