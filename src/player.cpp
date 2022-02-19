#include "yahtzee/player.h"

namespace yahtzee
{
    Player::Player(std::string name)
        : __name(name), __score_cards(nullptr)
    {
    }

    Player::~Player()
    {
        if (__score_cards != nullptr)
        {
            delete[] __score_cards;
        }
    }

    void Player::set_name(std::string name)
    {
        __name = name;
    }

    std::string Player::get_name() const
    {
        return __name;
    }

    void Player::set_scorecards(uint16_t scorecards)
    {
        // Method to set the amount of scorecards
        if (__score_cards != nullptr)
        {
            delete[] __score_cards;
        }

        __score_cards = new ScoreCard[scorecards];
    }
}