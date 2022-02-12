#ifndef __SCORECARDENTRY_H__
#define __SCORECARDENTRY_H__

#include <string>
#include "entity.h"

namespace yahtzee
{
    // Class that represents a item on the score card
    class ScoreCardEntry : public Entity
    {
    private:
        // The points written on this entry
        uint16_t __points;

        // The name of this entry
        std::string __name;

    public:
        // Constructors
        ScoreCardEntry();
        ScoreCardEntry(std::string name);

        // Setters and getters
        void set_points(const uint16_t points);
        uint16_t get_points() const;
        void set_name(std::string name);
        std::string get_name() const;

        // Operators
        void operator=(uint16_t points);
    };

    void operator+=(uint16_t &uint, ScoreCardEntry &entry);
}

#endif