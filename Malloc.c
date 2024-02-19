#include <stdlib.h>

int main() {
    int stackVar = 10; // Stored on the stack
    
    // Dynamically allocating memory on the heap
    int* heapVar = (int*)malloc(sizeof(int));
    *heapVar = 20;
    
    free(heapVar); // Freeing heap memory
}
