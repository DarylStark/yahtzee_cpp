#include "yahtzee/scorecardentry.h"

namespace yahtzee
{
    ScoreCardEntry::ScoreCardEntry()
        : __points(0), __name("Undefined")
    {
    }

    ScoreCardEntry::ScoreCardEntry(std::string name)
        : __points(0), __name(name)
    {
    }

    void ScoreCardEntry::set_points(const uint16_t points)
    {
        __points = points;
    }

    uint16_t ScoreCardEntry::get_points() const
    {
        return __points;
    }

    void ScoreCardEntry::set_name(std::string name)
    {
        __name = name;
    }

    std::string ScoreCardEntry::get_name() const
    {
        return __name;
    }

    // Operators
    void ScoreCardEntry::operator=(uint16_t points)
    {
        set_points(points);
    }

    // We overload the += operator for the uint16_t type so we can easily add
    // entires to a uint16_t. We can use this to calculate totals for, for
    // instance, a ScoreCard.
    void operator+=(uint16_t &uint, ScoreCardEntry &entry)
    {
        uint += entry.get_points();
    }
}