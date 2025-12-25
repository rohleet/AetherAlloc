#ifndef BLOCK_H
#define BLOCK_H

#include<cstddef>
#include<cstdlib>

constexpr size_t BLOCK_SIZE = 32;
constexpr size_t NUM_BLOCKS = 1024;
constexpr size_t POOL_SIZE = BLOCK_SIZE * NUM_BLOCKS;

struct Block
{
    Block* next;
};

extern Block* freeList;
extern Block* freeListEnd;

#endif