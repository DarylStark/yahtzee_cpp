#ifndef __ENTITY_H__
#define __ENTITY_H__

// Class that represents all entities in the game
class Entity
{
private:
    static uint32_t __entity_count;
    static uint32_t __next_id;
    uint32_t __id;

public:
    Entity()
        : __id(__next_id++)
    {
        // Increase the entity counter
        __entity_count++;
    }

    virtual ~Entity()
    {
        // Decrease the entity counter
        __entity_count--;
    }

    static uint32_t get_count()
    {
        return __entity_count;
    }
};

uint32_t Entity::__entity_count = 0;
uint32_t Entity::__next_id = 0;

#endif