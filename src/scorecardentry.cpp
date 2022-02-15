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
    ScoreCardEntryNumber::ScoreCardEntryNumber(const uint16_t number, std::string name)
        : ScoreCardEntry(name)
    {
        set_number(number);
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

    void ScoreCardEntryNumber::set_points_for_dieset(const DieSet &set)
    {
        // Method to set the correct amount of points for a specific DieSet
        // TODO: Implement
    }

    uint16_t ScoreCardEntryNumber::get_points_for_dieset(const DieSet &set)
    {
        // Method to set the correct amount of points for a specific DieSet
        // TODO: Implement
    }

    /***
     * ScoreCardEntryMultiple
     ***/

    // Constructor sets default values
    ScoreCardEntryMultiple::ScoreCardEntryMultiple(const uint16_t multiplier, std::string name)
        : ScoreCardEntry(name)
    {
        set_multiplier(multiplier);
    }

    // Method to set the amount of multiples needed for a ScoreCardEntryMultiple
    // entry.
    void ScoreCardEntryMultiple::set_multiplier(const uint16_t multiplier)
    {
        if (multiplier > 0 && multiplier <= 6)
        {
            __multiplier = multiplier;
        }
    }

    // Method to set the points for the object
    void ScoreCardEntryMultiple::set_points(const uint16_t points)
    {
        // We can only set the points if they are valid for this entry. If it is
        // invalid, we set the points to 0
        __points = 0;
        if (points >= __multiplier && points <= 30)
        {
            __points = points;
        }
    }

    void ScoreCardEntryMultiple::set_points_for_dieset(const DieSet &set)
    {
        // Method to set the correct amount of points for a specific DieSet
        // TODO: Implement
    }

    uint16_t ScoreCardEntryMultiple::get_points_for_dieset(const DieSet &set)
    {
        // Method to set the correct amount of points for a specific DieSet
        // TODO: Implement
    }

    /***
     * ScoreCardEntryFullHouse
     */

    // Constructor sets default values
    ScoreCardEntryFullHouse::ScoreCardEntryFullHouse(std::string name)
        : ScoreCardEntry(name)
    {
    }

    // Method to set the points for the object
    void ScoreCardEntryFullHouse::set_points(uint16_t points)
    {
        // We can only set the points if they are valid for this entry. If it is
        // invalid, we set the points to 0. For Full House, there are only two
        // possibilities: 25 points or no points.
        __points = 0;
        if (points == 25)
        {
            __points = 25;
        }
    }

    void ScoreCardEntryFullHouse::set_points_for_dieset(const DieSet &set)
    {
        // Method to set the correct amount of points for a specific DieSet
        // TODO: Implement
    }

    uint16_t ScoreCardEntryFullHouse::get_points_for_dieset(const DieSet &set)
    {
        // Method to set the correct amount of points for a specific DieSet
        // TODO: Implement
    }

    /***
     * ScoreCardEntryStraight
     */

    // Constructor sets default values
    ScoreCardEntryStraight::ScoreCardEntryStraight(bool is_small_straight, std::string name)
        : __is_small_straight(is_small_straight), ScoreCardEntry(name)
    {
    }

    // Method to set the points for the object
    void ScoreCardEntryStraight::set_points(uint16_t points)
    {
        // We can only set the points if they are valid for this entry. If it is
        // invalid, we set the points to 0
        __points = 0;
        if (points == 30 && __is_small_straight)
        {
            __points = 30;
        }
        else if (points == 40 && !__is_small_straight)
        {
            __points = 40;
        }
    }

    void ScoreCardEntryStraight::set_points_for_dieset(const DieSet &set)
    {
        // Method to set the correct amount of points for a specific DieSet
        // TODO: Implement
    }

    uint16_t ScoreCardEntryStraight::get_points_for_dieset(const DieSet &set)
    {
        // Method to set the correct amount of points for a specific DieSet
        // TODO: Implement
    }

    /***
     * ScoreCardEntryYahtzee
     ***/

    // Constructor sets default values
    ScoreCardEntryYahtzee::ScoreCardEntryYahtzee(std::string name)
        : ScoreCardEntry(name)
    {
    }

    void ScoreCardEntryYahtzee::set_points(uint16_t points)
    {
        // We can only set the points if they are valid for this entry. If it is
        // invalid, we set the points to 0
        __points = points == 50 ? points : 0;
    }

    void ScoreCardEntryYahtzee::set_points_for_dieset(const DieSet &set)
    {
        // Method to set the correct amount of points for a specific DieSet
        // TODO: Implement
    }

    uint16_t ScoreCardEntryYahtzee::get_points_for_dieset(const DieSet &set)
    {
        // Method to set the correct amount of points for a specific DieSet
        // TODO: Implement
    }

    /***
     * ScoreCardEntryFree
     ***/

    // Constructor sets default values
    ScoreCardEntryFree::ScoreCardEntryFree(std::string name)
        : ScoreCardEntry(name)
    {
    }

    void ScoreCardEntryFree::set_points(uint16_t points)
    {
        // We can only set the points if they are valid for this entry. If it is
        // invalid, we set the points to 0
        __points = points >= 5 && points <= 30 ? points : 0;
    }

    void ScoreCardEntryFree::set_points_for_dieset(const DieSet &set)
    {
        // Method to set the correct amount of points for a specific DieSet
        // TODO: Implement
    }

    uint16_t ScoreCardEntryFree::get_points_for_dieset(const DieSet &set)
    {
        // Method to set the correct amount of points for a specific DieSet
        // TODO: Implement
    }
}