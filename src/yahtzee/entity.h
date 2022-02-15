#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <cstdint>

namespace yahtzee
{
    // Class that represents all entities in the game
    class Entity
    {
    private:
        static uint32_t __entity_count;
        static uint32_t __next_id;
        uint32_t __id;

    public:
        Entity();
        virtual ~Entity();
        static uint32_t get_count();
    };
}

#endif