#ifndef __DIE_H__
#define __DIE_H__

#include <random>
#include "entity.h"

namespace yahtzee
{
    // A die can be used to throw
    class Die : public Entity
    {
    private:
        uint16_t __last_value;
        bool __is_locked;

    public:
        Die();
        uint16_t get_last_value();
        uint16_t roll();
        void lock();
        void unlock();
        bool is_locked() const;
    };
}

#endif