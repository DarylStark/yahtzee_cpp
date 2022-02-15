#ifndef __DIESET_H__
#define __DIESET_H__

#include <vector>
#include "entity.h"
#include "die.h"

namespace yahtzee
{
    // A die set is a set of dies
    class DieSet : public Entity
    {
    private:
        std::vector<Die> __dies;
        uint16_t __die_count;

    public:
        DieSet(uint16_t die_count = 5);
        void roll();
        void lock(uint16_t die_index);
        void unlock(uint16_t die_index);
        uint16_t get_specific_count(uint16_t points) const;
        Die get_die(uint16_t index) const;
        uint16_t get_sum() const;

        Die operator[](uint16_t index) const;
    };
}

#endif