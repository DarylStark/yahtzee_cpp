#ifndef __YAHTZEE_H__
#define __YAHTZEE_H__

#include <iostream>
#include <vector>
#include "entity.h"
#include "player.h"

namespace yahtzee
{
    // The class for the game
    class Yahtzee : public Entity
    {
    private:
        std::vector<Player> __players;

    public:
        void add_player(Player player);
        uint16_t get_player_count() const;
    };
}

#endif