#ifndef __SCORECARD_H__
#define __SCORECARD_H__

#include "entity.h"
#include "scorecardentry.h"

// A ScoreCard represents a scorecard for a player. A player has one of these
// composed.
class ScoreCard : public Entity
{
private:
    // Score for upper sections
    ScoreCardEntry __entries[13];

    uint16_t get_total(uint16_t start, uint16_t end)
    {
        // Method to get the sum of a few entries
        uint16_t sum = 0;
        for (uint16_t i = start; i < end; i++)
        {
            sum += __entries[i];
        }
        return sum;
    }

public:
    // Setters
    void set_score(uint16_t index, uint16_t score)
    {
        // Set the sore for a specific entry
        // TODO: if a index is specified that is too high or too low, throw
        //       an exception
        __entries[index] = score;
    }

    // Getters
    uint16_t get_upper_total(bool include_bonus = false)
    {
        // Method to calculate the total of the upper half of the ScoreCard. If
        // the user wants, he can exclude the 'bonus' that is received after
        // having 63 or higher for the numbers.

        // Calculate the sum of the numbers
        uint16_t sum = get_total(0, 6);

        // Check if we need to add the bonus
        if (include_bonus)
        {
            if (sum >= 63)
            {
                sum += 35;
            }
        }

        // Return the sum
        return sum;
    }

    uint16_t get_lower_total()
    {
        // Method to calculate the sum of the entries on the lower half of the
        // ScoreCard.
        return get_total(6, 13);
    }
    uint16_t get_total()
    {
        // Method to calculate the total number of points on this ScoreCard
        return get_lower_total() + get_upper_total();
    }
};

#endif