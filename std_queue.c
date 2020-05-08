#include "include/std_queue.h"

int queue(struct queue* q){
    for(int i = 0; i < 5; ++i){
      heap[5]
    }
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;
    q.empty = &empty;
    q.size = &size;
    q.front = &front;
    q.back = &back;
    q.push_back = &push_back;
    q.pop_front = &push_front;
}

int empty(struct queue* q){
  return q -> size == 0;
}

int size(struct queue* q){
  return q -> size;        
}

char front(struct queue* q){
  return q -> head -> val;
}

char back(struct queue* q){
  return q -> tail -> val;        
}

char push_back(struct queue* q, char c){
        
}
