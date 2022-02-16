#ifndef __SCORECARDENTRY_H__
#define __SCORECARDENTRY_H__

#include <string>
#include "dieset.h"
#include "entity.h"

namespace yahtzee
{
    // Class that represents a item on the score card
    class ScoreCardEntry : public Entity
    {
    protected:
        // The points written on this entry
        uint16_t __points;
        bool __set;

        // The name of this entry
        std::string __name;

    public:
        ScoreCardEntry(std::string name = "");
        virtual void set_points(const uint16_t points) = 0;
        virtual uint16_t get_points_for_dieset(const DieSet &set) const = 0;
        uint16_t get_points() const;
        void set_name(std::string name);
        std::string get_name() const;
        void set_points_for_dieset(const DieSet &set);
        bool is_set() const;

        // Operators
        void operator=(uint16_t points);
    };

    void operator+=(uint16_t &uint, ScoreCardEntry &entry);

    // Class that represents a item on the score card that is counted by the
    // amount of a specific number.
    class ScoreCardEntryNumber : public ScoreCardEntry
    {
    private:
        uint16_t __number;

    public:
        ScoreCardEntryNumber(const uint16_t number = 1, std::string name = "");
        void set_number(const uint16_t number);
        void set_points(const uint16_t points);
        void set_points_for_dieset(const DieSet &set);
        uint16_t get_points_for_dieset(const DieSet &set) const;
    };

    // Class that represents a item that is a multiple of one specific number,
    // like the 'Three of a kid' en 'Four or a kind' entries on the ScoreCard.
    class ScoreCardEntryMultiple : public ScoreCardEntry
    {
    private:
        uint16_t __multiplier;

    public:
        ScoreCardEntryMultiple(const uint16_t multiplier = 1, std::string name = "");
        void set_multiplier(const uint16_t multipier);
        void set_points(const uint16_t points);
        uint16_t get_points_for_dieset(const DieSet &set) const;
    };

    // Class that represents Full House
    class ScoreCardEntryFullHouse : public ScoreCardEntry
    {
    public:
        ScoreCardEntryFullHouse(std::string name = "");
        void set_points(uint16_t points);
        uint16_t get_points_for_dieset(const DieSet &set) const;
    };

    // Class that represents a straight
    class ScoreCardEntryStraight : public ScoreCardEntry
    {
    private:
        bool __is_small_straight;

    public:
        ScoreCardEntryStraight(bool is_small_straight = false, std::string name = "");
        void set_points(uint16_t points);
        uint16_t get_points_for_dieset(const DieSet &set) const;
    };

    // Class that represents a Yahtzee
    class ScoreCardEntryYahtzee : public ScoreCardEntry
    {
    public:
        ScoreCardEntryYahtzee(std::string name = "");
        void set_points(uint16_t points);
        uint16_t get_points_for_dieset(const DieSet &set) const;
    };

    // Class that represents a free field entry, like 'chance'
    class ScoreCardEntryFree : public ScoreCardEntry
    {
    public:
        ScoreCardEntryFree(std::string name = "");
        void set_points(uint16_t points);
        uint16_t get_points_for_dieset(const DieSet &set) const;
    };
}

#endif