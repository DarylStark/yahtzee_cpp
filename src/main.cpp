#include <iostream>
#include "yahtzee/yahtzee.h"
#include "yahtzee/scorecardentry.h"
#include "yahtzee/dieset.h"

int main()
{
    using yahtzee::DieSet;
    using yahtzee::ScoreCardEntryYahtzee;

    // Four of a kind
    ScoreCardEntryYahtzee entry;

    // Roll dies
    DieSet x;

    for (int i = 0; i < 200; i++)
    {
        std::cout << "Roll:" << std::endl;
        x.roll();

        for (int j = 0; j < 5; j++)
        {
            if (x[j].get_last_value() == 1)
                x.lock(j);
        }
    }

    // Get theoretic points
    std::cout << "Points for dieset: " << entry.get_points_for_dieset(x) << std::endl;

    // Set points
    entry.set_points_for_dieset(x);
    std::cout << "Set " << entry.get_points() << " points" << std::endl;

    for (int i = 0; i < 5; i++)
        std::cout << x[i].get_last_value() << " ";
    std::cout << std::endl;
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