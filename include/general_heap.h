#ifndef __GENERAL_HEAP
#define __GENERAL_HEAP

#define HEAP_SIZE 10

typedef struct heap_struct{
	int free_heap; // left most free leaf of the heap
	int (*compare)(void* , void* ); // compare function for heap elements
	void* heap[HEAP_SIZE];	// datastructure representing the heap
} heap_struct; 


void push(heap_struct* h, void* value);

int empty(heap_struct* h);

void pop(heap_struct* h);

void* front(heap_struct* h);

void init_heap_struct(heap_struct* h, int (*comp)(void*, void*));

#endif

