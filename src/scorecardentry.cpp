#include "yahtzee/scorecardentry.h"

namespace yahtzee
{
    ScoreCardEntry::ScoreCardEntry(std::string name)
        : __points(0), __name(name)
    {
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

    /***
     * ScoreCardEntryNumber
     ***/

    // Constructor sets default values
    ScoreCardEntryNumber::ScoreCardEntryNumber(uint16_t number, std::string name)
        : ScoreCardEntry(name), __number(number)
    {
    }

    // Method to set the number for ScoreCardEntryNumber objects
    void ScoreCardEntryNumber::set_number(const uint16_t number)
    {
        if (number > 0 && number <= 6)
            __number = number;
    }

    // Method to set the points for ScoreCardEntryNumber objects
    void ScoreCardEntryNumber::set_points(const uint16_t points)
    {
        // We can only set the points if they are valid for this entry. If it is
        // invalid, we set the points to 0.
        __points = 0;
        if (points % __number == 0 && points <= __number * 5)
        {
            __points = points;
        }
    }

}