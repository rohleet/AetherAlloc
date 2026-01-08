#include "../src/allocator.h"
#include <iostream>

using namespace std;

int main() {

    Allocator a;

    int* ptr = (int*)a.allocate();

    a.deallocate(ptr);

    return 0;
}