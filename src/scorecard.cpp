#include "yahtzee/scorecard.h"

namespace yahtzee
{
    ScoreCard::ScoreCard()
    {
        // Configure the entries for the numbers
        for (int i = 0; i < 6; i++)
        {
            __numbers[i].set_number(i + 1);
        }
    }

    uint16_t ScoreCard::get_total(uint16_t start, uint16_t end) const
    {
        // TODO: Implement
        return 0;
    }

    void ScoreCard::set_score(uint16_t index, uint16_t score)
    {
        // Set the sore for a specific entry
        // TODO: if a index is specified that is too high or too low, throw
        //       an exception
        //__entries[index] = score;
    }

    // Getters
    uint16_t ScoreCard::get_upper_total(bool include_bonus /* = false */) const
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

    uint16_t ScoreCard::get_lower_total() const
    {
        // Method to calculate the sum of the entries on the lower half of the
        // ScoreCard.
        return get_total(6, 13);
    }
    uint16_t ScoreCard::get_total() const
    {
        // Method to calculate the total number of points on this ScoreCard
        return get_lower_total() + get_upper_total();
    }
}