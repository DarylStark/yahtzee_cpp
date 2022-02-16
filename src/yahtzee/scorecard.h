#ifndef __SCORECARD_H__
#define __SCORECARD_H__

#include <string>
#include "entity.h"
#include "dieset.h"
#include "scorecardentry.h"

namespace yahtzee
{
    // A ScoreCard represents a scorecard for a player. A player has one of these
    // composed.
    class ScoreCard : public Entity
    {
    private:
        ScoreCardEntry *__entries[13];
        uint16_t get_total(uint16_t start, uint16_t end) const;

    public:
        ScoreCard();
        ~ScoreCard();
        uint16_t get_upper_total(bool include_bonus = false) const;
        uint16_t get_lower_total() const;
        uint16_t get_total() const;
        const ScoreCardEntry &get_entry(uint16_t index) const;
        void set_points_for_dieset(uint16_t index, DieSet &set);

        const ScoreCardEntry &operator[](uint16_t index) const;
    };
}

#endif