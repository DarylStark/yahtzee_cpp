#include "yahtzee/yahtzee.h"

namespace yahtzee
{
    void Yahtzee::add_player(Player player)
    {
        __players.push_back(player);
    }

    uint16_t Yahtzee::get_player_count() const
    {
        return __players.size();
    }
}