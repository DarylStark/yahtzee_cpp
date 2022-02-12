#ifndef __SCORECARDENTRY_H__
#define __SCORECARDENTRY_H__

#include "entity.h"

// Class that represents a item on the score card
class ScoreCardEntry : public Entity
{
private:
    // The points written on this entry
    uint16_t __points;

public:
    // Constructors
    ScoreCardEntry() : __points(0) {}

    // Setters and getters
    void set(const uint16_t points)
    {
        __points = points;
    }

    uint16_t get()
    {
        return __points;
    }

    // Operators
    void operator=(uint16_t points)
    {
        set(points);
    }
};

// We overload the += operator for the uint16_t type so we can easily add
// entires to a uint16_t. We can use this to calculate totals for, for
// instance, a ScoreCard.
void operator+=(uint16_t &uint, ScoreCardEntry &entry)
{
    uint += entry.get();
}

#endif