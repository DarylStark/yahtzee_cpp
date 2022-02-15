#ifndef __SCORECARD_H__
#define __SCORECARD_H__

#include "entity.h"
#include "scorecardentry.h"

namespace yahtzee
{
    // A ScoreCard represents a scorecard for a player. A player has one of these
    // composed.
    class ScoreCard : public Entity
    {
    private:
        ScoreCardEntryNumber __numbers[6];
        uint16_t get_total(uint16_t start, uint16_t end) const;

    public:
        ScoreCard();
        void set_score(uint16_t index, uint16_t score);
        uint16_t get_upper_total(bool include_bonus = false) const;
        uint16_t get_lower_total() const;
        uint16_t get_total() const;
    };
}

#endif