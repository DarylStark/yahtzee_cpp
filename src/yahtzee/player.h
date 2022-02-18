#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>
#include "entity.h"
#include "scorecard.h"

namespace yahtzee
{
    // Class that represents a player in the game
    class Player : public Entity
    {
    private:
        std::string __name;
        ScoreCard *__score_cards;

    public:
        Player(std::string name = "");

        void set_name(std::string name);
        std::string get_name() const;
    };
}

#endif