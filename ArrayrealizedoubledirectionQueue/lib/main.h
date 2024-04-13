#ifndef MIAN_H
#define MAIN_H

typedef struct arrayQueue
{
    int *array;
    int front;
    int quesize;
    int quecapacity;
    int queexpand;
}arrayQueue;

arrayQueue* newArrayQueue();
void delArrayQueue(arrayQueue* queue);
void push_first(arrayQueue* queue,int num);
void push_last(arrayQueue* queue, int num);
void expandQueue(arrayQueue* queue);
int calculation(arrayQueue* queue,int current);
int Qsize(arrayQueue* queue);
bool isEmpty(arrayQueue* queue);
int peek_first(arrayQueue* queue);
int peek_last(arrayQueue* queue);
int pop_first(arrayQueue* queue);
int pop_last(arrayQueue* queue);
void printQueue(arrayQueue* queue);

#endif