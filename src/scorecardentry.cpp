#include "yahtzee/scorecardentry.h"

namespace yahtzee
{
    ScoreCardEntry::ScoreCardEntry(std::string name)
        : __points(0), __set(false), __name(name)
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

    void ScoreCardEntry::set_points_for_dieset(const DieSet &set)
    {
        // Method to set the correct amount of points for a specific DieSet
        set_points(get_points_for_dieset(set));
    }

    bool ScoreCardEntry::is_set() const
    {
        return __set;
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
        __set = true;
        __points = 0;
        if (points % __number == 0 && points <= __number * 5)
        {
            __points = points;
        }
    }

    uint16_t ScoreCardEntryNumber::get_points_for_dieset(const DieSet &set) const
    {
        // Method to get the correct amount of points for a specific DieSet
        return set.get_specific_count(__number) * __number;
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
        __set = true;
        __points = 0;
        if (points >= __multiplier && points <= 30)
        {
            __points = points;
        }
    }

    uint16_t ScoreCardEntryMultiple::get_points_for_dieset(const DieSet &set) const
    {
        // Method to set the correct amount of points for a specific DieSet
        for (uint16_t index = 0; index < 5; index++)
        {
            if (set.get_specific_count(set[index].get_last_value()) >= __multiplier)
            {
                return set.get_sum();
            }
        }
        return 0;
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
        __set = true;
        __points = 0;
        if (points == 25)
        {
            __points = 25;
        }
    }

    uint16_t ScoreCardEntryFullHouse::get_points_for_dieset(const DieSet &set) const
    {
        // Method to set the correct amount of points for a specific DieSet
        uint16_t values = set.get_distribution();
        if (values == 2)
        {
            int x = set.get_max();
            int y = set.get_min();
            if (
                (set.get_specific_count(set.get_min()) == 2 || set.get_specific_count(set.get_min()) == 3) &&
                (set.get_specific_count(set.get_max()) == 2 || set.get_specific_count(set.get_max()) == 3))
            {
                return 25;
            }
        }
        return 0;
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
        __set = true;
        __points = 0;
        if ((points == 30 && __is_small_straight) || (points == 40 && !__is_small_straight))
        {
            __points = points;
        }
    }

    uint16_t ScoreCardEntryStraight::get_points_for_dieset(const DieSet &set) const
    {
        // Method to set the correct amount of points for a specific DieSet

        // If this is a small straight, we need one of the following
        // 1, 2, 3, 4
        //    2, 3, 4, 5
        //       3, 4, 5, 6
        // If this is a big straight, we need one of the following
        // 1, 2, 3, 4, 5
        //    2, 3, 4, 5, 6
        // That means that we always need a three and a four. At least

        if (set.get_specific_count(3) == 0 || set.get_specific_count(4) == 0)
            return 0;

        if (__is_small_straight)
        {
            if (
                (set.get_specific_count(1) > 0 && set.get_specific_count(2) > 0) ||
                (set.get_specific_count(2) > 0 && set.get_specific_count(5) > 0) ||
                (set.get_specific_count(5) > 0 && set.get_specific_count(6) > 0))
            {
                return 30;
            }

            // Not a correct small straight
            return 0;
        }

        // Big straight, we always need the 2 and the 5
        if (set.get_specific_count(2) == 0 || set.get_specific_count(5) == 0)
            return 0;

        // We also need either the 1 or the 6
        if (set.get_specific_count(1) > 0 || set.get_specific_count(6) > 0)
        {
            return 40;
        }

        // Invalid straight
        return 0;
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
        __set = true;
        __points = points == 50 ? points : 0;
    }

    uint16_t ScoreCardEntryYahtzee::get_points_for_dieset(const DieSet &set) const
    {
        // Method to set the correct amount of points for a specific DieSet
        if (set.get_specific_count(set[0].get_last_value()) == 5)
            return 50;
        return 0;
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
        __set = true;
        __points = points >= 5 && points <= 30 ? points : 0;
    }

    uint16_t ScoreCardEntryFree::get_points_for_dieset(const DieSet &set) const
    {
        // Method to set the correct amount of points for a specific DieSet
        return set.get_sum();
    }
}