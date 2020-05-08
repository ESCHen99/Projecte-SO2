#ifndef __STD_QUEUE__
#define __STD_QUEUE__

struct queue_elem{
  queue_elem* next;
  char val;
};

char heap[5];

struct queue{
    queue_elem head;
    queue_elem tail;
    int size;
    int (*queue)(struct queue);
    int (*empty)(void);
    int (*size)(void);
    char (*front)(void);
    char (*back)(void)
    void (*push_back)(void);
    void (*pop_front)(char);
}

int queue(struct queue* q);

int empty();

int size();

char front();

char back();

void push_back();

void pop_front(char c);


#endif

