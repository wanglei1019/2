#ifndef MIAN_H
#define MAIN_H

typedef struct list
{
    struct list* next;
    int val;
}Listnode;

typedef struct queue
{
    Listnode *front,*rear;
    int size;
}queue;

queue* newQueueList();
void delQueueList(queue* queuelist);
void push(queue* queuelist,int num);
int size(queue* queuelist);
bool isEmpty(queue* queuelist);
int peek(queue* queuelist);
int pop(queue* queuelist);
void printQueueList(queue* queuelist);

#endif