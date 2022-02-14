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
};