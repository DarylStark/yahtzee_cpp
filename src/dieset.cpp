#include "yahtzee/dieset.h"

namespace yahtzee
{
    DieSet::DieSet(uint16_t die_count)
        : __die_count(die_count)
    {
        __dies.insert(__dies.begin(), __die_count, Die());
    }

    void DieSet::roll()
    {
        // Method to roll the dies in the set
        for (Die &die : __dies)
        {
            die.roll();
        }
    }

    void DieSet::lock(uint16_t die_index)
    {
        if (die_index >= __die_count)
        {
            // TODO: throw exception
            return;
        }

        __dies[die_index].lock();
    }

    void DieSet::unlock(uint16_t die_index)
    {
        if (die_index >= __die_count)
        {
            // TODO: throw exception
            return;
        }

        __dies[die_index].unlock();
    }

    uint16_t DieSet::get_specific_count(uint16_t points) const
    {
        // Method to get the number of dies with a specific value. For intance,
        // this method can be used to get the amount of dies that is landed on
        // the number 3. This can be used to calculate the type of score this
        // DieSet is.
        uint16_t count = 0;
        for (const Die &die : __dies)
        {
            if (die.get_last_value() == points)
                count++;
        }
        return count;
    }

    const Die &DieSet::get_die(uint16_t index) const
    {
        // Method that returns the value of a specific die
        if (index > 4)
        {
            // TODO: Exception
        }

        return __dies[index];
    }

    uint16_t DieSet::get_sum() const
    {
        // Method to get the sum of all dies
        uint16_t sum = 0;
        for (const Die &die : __dies)
        {
            sum += die.get_last_value();
        }
        return sum;
    }

    uint16_t DieSet::get_distribution() const
    {
        // Method that returns the number of unique values for the dies
        std::set<uint16_t> unique_values;
        for (const Die &die : __dies)
        {
            unique_values.insert(die.get_last_value());
        }
        return unique_values.size();
    }

    uint16_t DieSet::get_max() const
    {
        // Method that returns the highest die in the set
        uint16_t max = 0;
        for (const Die &die : __dies)
        {
            if (die.get_last_value() > max)
                max = die.get_last_value();
        }
        return max;
    }

    uint16_t DieSet::get_min() const
    {
        // Method that returns the lowest die in the set
        uint16_t min = 7;
        for (const Die &die : __dies)
        {
            if (die.get_last_value() < min)
                min = die.get_last_value();
        }
        return min;
    }

    const Die &DieSet::operator[](uint16_t index) const
    {
        return get_die(index);
    }
};