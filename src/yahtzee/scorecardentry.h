#ifndef __SCORECARDENTRY_H__
#define __SCORECARDENTRY_H__

#include <string>
#include "entity.h"

namespace yahtzee
{
    // Class that represents a item on the score card
    class ScoreCardEntry : public Entity
    {
    protected:
        // The points written on this entry
        uint16_t __points;

        // The name of this entry
        std::string __name;

    public:
        // Constructors
        ScoreCardEntry(std::string name = "");

        // Setters and getters
        virtual void set_points(const uint16_t points) = 0;
        uint16_t get_points() const;
        void set_name(std::string name);
        std::string get_name() const;

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
        ScoreCardEntryNumber(uint16_t number = 1, std::string name = "");
        void set_number(const uint16_t number);
        void set_points(const uint16_t points);
    };
}

#endif