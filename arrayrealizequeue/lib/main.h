#ifndef MIAN_H
#define MAIN_H

typedef struct queue
{
    int* array;
    int front;
    int queSzie;
    int quecapacity;
    int expand;
    int size;
}queue;
queue* newqQueueArray();
void DelQueueArray(queue* queuearray);
void ExpandQueueArray(queue* queuearray);
void push(queue* queuearray,int num);
int Queuesize(queue* queuearray);
bool isEmpty(queue* queuearray);
int peek(queue* queuearray);
int pop(queue* queuearray);
void printQueueArray(queue* queuearray);

#endif