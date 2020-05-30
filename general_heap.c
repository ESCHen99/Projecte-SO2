#include <general_heap.h>
#include <types.h>



/**
struct stack {
    int top;
    int (*push)(void*, void*);
    char *(*pop)(struct stack *self);
    void (*init)(struct stack *self);
};*/


int compare(heap_struct* h, void* i, void* j){
	if(i == NULL || j == NULL) return 0;
	else return h -> compare(i, j);
}

int int_compare(void* i, void* j){
	return (int )i > (int) j;
}


void swap(void** a, void** b){
	void* aux = *a;
	*a = *b;
	*b = aux;
}
/**
void print_heap(heap_struct* hp){
	for(int i = 0; i < HEAP_SIZE; ++i){
		if(hp->heap[i] == NULL) printf("%d ", -1);
		else printf("%d ", (int) hp -> heap[i]);
	}
	printf("\n");
}
*/
int parent(int pos){
  return pos / 2;
}

int left_child(int pos){
  return 2 * pos;
}

int right_child(int pos){
  return 2 * pos + 1;
}

void sink(heap_struct* h, int pos){
	if(compare(h, h -> heap[left_child(pos)], h -> heap[pos])){
		swap(&(h -> heap[left_child(pos)]), &(h -> heap[pos]));
		sink(h, left_child(pos));
	}
	if(compare(h, h -> heap[right_child(pos)], h -> heap[pos])){
		swap(&(h -> heap[right_child(pos)]), &(h -> heap[pos]));
		sink(h, right_child(pos));	
	}
}

void flood(heap_struct* h, int pos){
	if(compare(h, h -> heap[pos], h -> heap[parent(pos)])){
		swap(&(h -> heap[pos]), &(h -> heap[parent(pos)]));
		flood(h, parent(pos));
	}
}

void push(heap_struct* h, void* value){
	h -> heap[h -> free_heap] = value;
	flood(h, h -> free_heap);
	++(h -> free_heap);
}

void pop(heap_struct* h){
	--(h -> free_heap);
	swap(&(h -> heap[1]), &(h -> heap[h -> free_heap]));
	//print_heap(h);
	h -> heap[h -> free_heap] = NULL;
	sink(h, 1);
}

void* front(heap_struct* h){
	return h -> heap[1];
}

void init_heap_struct(heap_struct* h, int (*comp)(void*, void*)){
	h -> free_heap = 1;
	h -> compare = comp;
	for(int i = 0; i < HEAP_SIZE; ++i) h -> heap[i] = NULL;
}

int empty(heap_struct* h){
	return h -> free_heap == 1;
}
/*
int main(){
	void* heap[4];
	struct heap_struct hp;
hp.free_heap = 1;
	hp.compare = int_compare;
	for(int i = 0; i < HEAP_SIZE; ++i) hp.heap[i] = NULL;	
	init_heap_struct(&hp, int_compare);
	push(&hp, (void*) 1);
	push(&hp, (void*) 5);
	//print_heap(&hp);
	push(&hp, (void*) 3);
	pop(&hp);
	push(&hp, (void*) 7);
	//print_heap(&hp);
}
*/
