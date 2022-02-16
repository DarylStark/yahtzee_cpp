#include "yahtzee/scorecard.h"

namespace yahtzee
{
    ScoreCard::ScoreCard()
    {
        // The constructor will create the needed entries

        // The names for the entries
        std::string names[] = {
            "Ones",
            "Twos",
            "Threes",
            "Fours",
            "Fives",
            "Sixes",
            "Three of a kind",
            "Four of a kind",
            "Full house",
            "Small straight",
            "Large straight",
            "Yahtzee",
            "Chance"};

        // Configure the 'number' entries (the top half)
        for (int i = 0; i < 6; i++)
        {
            __entries[i] = new ScoreCardEntryNumber(i + 1, names[i]);
        }

        // Configure the 'Three of a kind' and 'Four of a kind' entries
        __entries[6] = new ScoreCardEntryMultiple(3, names[6]);
        __entries[7] = new ScoreCardEntryMultiple(4, names[7]);

        // Configure the 'weird' entries; full house and the straights
        __entries[8] = new ScoreCardEntryFullHouse(names[8]);
        __entries[9] = new ScoreCardEntryStraight(true, names[9]);
        __entries[10] = new ScoreCardEntryStraight(false, names[10]);

        // Yathzee
        __entries[11] = new ScoreCardEntryYahtzee(names[11]);

        // Chance
        __entries[12] = new ScoreCardEntryFree(names[12]);
    }

    ScoreCard::~ScoreCard()
    {
        for (int i = 0; i < 11; i++)
        {
            if (__entries[i] != nullptr)
                delete __entries[i];
        }
    }

    uint16_t ScoreCard::get_total(uint16_t start, uint16_t end) const
    {
        // Method that returns the total for a specific range of entries
        uint16_t sum = 0;
        for (int i = start; i < end; i++)
        {
            sum += __entries[i]->get_points();
        }
        return sum;
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

    const ScoreCardEntry &ScoreCard::get_entry(uint16_t index) const
    {
        // Method that returns the value of a specific entry
        if (index > 5)
        {
            // TODO: Exception
        }

        return *(__entries[index]);
    }

    const ScoreCardEntry &ScoreCard::operator[](uint16_t index) const
    {
        return get_entry(index);
    }
}