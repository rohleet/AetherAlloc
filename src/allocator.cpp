#include "allocator.h"
#include<iostream>
#include <exception>
#include<new>

using namespace std;

Allocator::Allocator() {
    Memory = malloc(POOL_SIZE);

    try
    {
        if (!Memory)
        {
            throw bad_alloc();
        }
        
    }
    catch(bad_alloc& b)
    {
        cout<<"Memory allocation failed due to internal errors exiting";
        exit(EXIT_FAILURE);
    }
    

    char* start = static_cast<char*>(Memory);

    if (NUM_BLOCKS == 1) {
        freeList=reinterpret_cast<Block*>(start);
        freeListEnd = freeList;
        freeListEnd->next = nullptr;
        return; 
    }
    
    for (int i = 0; i < NUM_BLOCKS-1; i++)
    {
        Block* current = reinterpret_cast<Block*>(start+BLOCK_SIZE*i);
        Block* next = reinterpret_cast<Block*>(start+BLOCK_SIZE*(i+1));
        current->next=next;
        if(i==NUM_BLOCKS-2){
            freeListEnd=next;
            freeListEnd->next=nullptr;
        }
    }

    freeList=reinterpret_cast<Block*>(start);
}

void* Allocator::allocate() {
        if(!freeList) return nullptr;
        Block* block = freeList;
        freeList=freeList->next;
        if(!freeList){
            freeListEnd=freeList;
        }
        return static_cast<void*>(block);
    }

void Allocator::deallocate(void* ptr) {
    if(!ptr){
        return;
    }
    if(freeListEnd){
        freeListEnd->next=static_cast<Block*>(ptr);
    }
    freeListEnd=static_cast<Block*>(ptr);
    freeListEnd->next = nullptr;
    if(!freeList){
        freeList=freeListEnd;
    }
}
