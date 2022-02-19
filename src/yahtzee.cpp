#include "yahtzee/yahtzee.h"

namespace yahtzee
{
    void Yahtzee::header(const std::string title)
    {
        // Method to display the header for the game

        uint16_t spaces = 76 - title.length();
        std::cout << '+' << std::string(78, '-') << '+' << std::endl;
        std::cout << "| " << title << std::string(spaces, ' ') << " |" << std::endl;
        std::cout << '+' << std::string(78, '-') << '+' << std::endl
                  << std::endl;
    }

    Yahtzee::Yahtzee()
        : __cards(0)
    {
        // Display the header
        header("Yahtzee - By Daryl Stark");

        // Initialize the game
        initialize();
    }

    void Yahtzee::initialize()
    {
        // Method that does the game initialization, like setting up the players
        // and the rules.

        std::cout << "# Game initialization" << std::endl
                  << std::endl;

        // Get the players

        std::cout << "Enter the names of the players. Leave empty when you're done entering players." << std::endl;
        std::cout << "At least one player name should be entered" << std::endl
                  << std::endl;

        uint16_t index = 1;
        while (true)
        {
            // Request the players name
            std::string new_name;
            std::cout << "Player #" << index << ": ";
            std::getline(std::cin, new_name);

            // If this was the last user, stop
            if (new_name == "" && index > 1)
            {
                break;
            }
            else if (new_name != "")
            {
                // Add a new Player object to the list of players
                __players.push_back(new_name);

                // Increase the counter
                index++;
            }
        }

        std::cout << std::endl
                  << "Cool! The game is getting played with " << __players.size() << " player(s)!"
                  << std::endl;

        // Set the rules

        std::cout << "Let's set some rules" << std::endl
                  << std::endl;

        std::cout << "How many scorecards do you want each user to have: ";
    }
}