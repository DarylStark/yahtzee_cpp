#include "yahtzee/die.h"

namespace yahtzee
{
    Die::Die()
        : __last_value(0), __is_locked(false)
    {
    }

    uint16_t Die::get_last_value()
    {
        return __last_value;
    }

    uint16_t Die::roll()
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

    void Die::lock()
    {
        __is_locked = true;
    }

    void Die::unlocked()
    {
        __is_locked = false;
    }

    bool Die::is_locked() const
    {
        return __is_locked;
    }
}