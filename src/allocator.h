#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include "block.h"

class Allocator{
public:

    void* Memory;

    Allocator();

    void* allocate();
    void deallocate(void* ptr);
};

#endif