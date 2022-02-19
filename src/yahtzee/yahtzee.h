#ifndef __YAHTZEE_H__
#define __YAHTZEE_H__

#include <iostream>
#include <vector>
#include <string>
#include "entity.h"
#include "player.h"

namespace yahtzee
{
    // The class for the game
    class Yahtzee : public Entity
    {
    private:
        std::vector<Player> __players;
        uint16_t __cards;

        // Private methods
        void header(const std::string title);

    public:
        // Constructor
        Yahtzee();

        // Phases of the game
        void initialize();
        void setup();
        void game();
        void end();

        // Methods to start the game
        void start();
    };
}

#endif