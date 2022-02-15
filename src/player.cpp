#include "yahtzee/player.h"

namespace yahtzee
{
    Player::Player(std::string name)
        : __name(name)
    {
    }

    void Player::set_name(std::string name)
    {
        __name = name;
    }

    std::string Player::get_name() const
    {
        return __name;
    }
}