#include <fixed_heap.h>

void init_tasks_heap(){
	for(int i = 0; i < HEAP_SIZE; ++i) heap[i] = 0;
	free_heap = 1;
}

void swap(T* a, T* b){ 
  T aux = *a; 
  *a = *b; 
  *b = aux;
}

int empty(){
	return free_heap == 1;
}

int size(){
	return free_heap	-	1;
}

int compare(T a, T b){ 
  if(a == FREE || b == FREE) return 0;
  if(a -> nice < b -> nice) return 1;
  return 0;
}

int parent(int pos){
  return pos / 2;
}

int left_child(int pos){
  return 2 * pos;
}

int right_child(int pos){
  return 2 * pos + 1;
}

void sink(int pos){
  if(compare(heap[left_child(pos)], heap[pos])){
    swap(&heap[left_child(pos)], &heap[pos]);
    sink(left_child(pos));
  }
  if(compare(heap[right_child(pos)], /*> = ?*/ heap[pos])){
    swap(&heap[right_child(pos)], &heap[pos]);
    sink(left_child(pos)); // Max heap no importa -1;
  }
}

void flood(int pos){
  if(compare(heap[pos], heap[parent(pos)])){
    swap(&heap[parent(pos)], &heap[pos]);
    flood(parent(pos));
  }
}

void push(T value){
  heap[free_heap] = value;
  flood(free_heap);
  ++free_heap;
}

void pop(){
  --free_heap;
  swap(&heap[1], &heap[free_heap]);
  heap[free_heap] = FREE;
  sink(1);
}

T front(){
  return heap[1];
}

