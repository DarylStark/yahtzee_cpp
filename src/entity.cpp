#include "yahtzee/entity.h"

namespace yahtzee
{
    uint32_t Entity::__entity_count = 0;
    uint32_t Entity::__next_id = 0;

    Entity::Entity()
        : __id(__next_id++)
    {
        // Increase the entity counter
        __entity_count++;
    }

    Entity::~Entity()
    {
        // Decrease the entity counter
        __entity_count--;
    }

    uint32_t Entity::get_count()
    {
        return __entity_count;
    }
}