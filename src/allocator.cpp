#include "allocator.h"

allocator::allocator() {
    memory = malloc(POOL_SIZE);

    char* start = (char*)memory;

    if (NUM_BLOCKS == 1) {
        freeListEnd = freeList;
        freeListEnd->next = nullptr;
        return;
    }
    
    for (int i = 0; i < NUM_BLOCKS-1; i++)
    {
        Block* current = (Block*)(start+BLOCK_SIZE*i);
        Block* next = (Block*)(start+BLOCK_SIZE*(i+1));
        current->next=next;
        if(i==NUM_BLOCKS-2){
            freeListEnd=next;
            freeListEnd->next=nullptr;
        }
    }

    freeList=(Block*)start;
}

void* allocator::allocate() {
        if(!freeList) return nullptr;
        Block* block = freeList;
        freeList=freeList->next;
        return (void*)block;
    }

void allocator::deallocate(void* ptr) {
    if(!ptr){
        return;
    }
    freeListEnd->next=(Block*)ptr;
    freeListEnd=(Block*)ptr;
}
