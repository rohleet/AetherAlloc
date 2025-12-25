#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include "block.h"

class allocator{
public:

    void* memory;

    allocator();

    void* allocate();
    void deallocate(void* ptr);
};

#endif