#include "yahtzee/dieset.h"
#include <iostream>

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
            std::cout << die.get_last_value() << std::endl;
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
};