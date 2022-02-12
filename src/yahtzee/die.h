#ifndef __DIE_H__
#define __DIE_H__

#include <random>
#include "entity.h"

// A die can be used to throw
class Die : public Entity
{
private:
    uint16_t __last_value;
    bool __is_locked;

public:
    Die() : __last_value(0), __is_locked(false) {}

    uint16_t get_last_value()
    {
        return __last_value;
    }

    uint16_t roll()
    {
        if (!__is_locked)
        {
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 6);

            __last_value = dist6(rng);
        }

        return __last_value;
    }

    void lock()
    {
        __is_locked = true;
    }

    void unlocked()
    {
        __is_locked = false;
    }

    bool is_locked() const
    {
        return __is_locked;
    }
};

#endif