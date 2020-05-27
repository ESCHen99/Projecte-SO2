#ifndef __FIXED_HEAP__
#define __FIXED_HEAP__

#include <sched.h>
#define T struct task_struct*
#define HEAP_SIZE NR_TASKS+1
#define FREE (T) NULL

T heap[HEAP_SIZE];
int free_heap;

void init_tasks_heap();

int empty();

int size();

void swap(T* a, T* b);

int compare(T a, T b);

void print_heap();

int parent(int pos);

int left_child(int pos);

int right_child(int pos);

void sink(int pos);

void flood(int pos);

void push(T value);

void pop();

T front();

#endif
