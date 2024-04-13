#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"
int main(int arge,char** argv)
{
    int data;
    arrayQueue* queue = newArrayQueue();
    while (scanf("%d",&data) == 1)
    {
        //push_first(queue,data);
        push_last(queue,data);
    }
    printf("successfully!\n");
    printf("the curret memory is %d and the size of queue is %d!\n",queue->quecapacity,queue->quesize);
    printQueue(queue);
    delArrayQueue(queue);
    return 0;
}
//构造初始化双向队列
arrayQueue* newArrayQueue()
{
    printf("the queue is successful to crate!\n");
    arrayQueue* queue = (arrayQueue*)malloc(sizeof(arrayQueue));
    queue->quecapacity = 10;
    queue->queexpand = 2;
    queue->array = (int*)malloc(sizeof(int)*queue->quecapacity);
    queue->front = queue->quesize = 0;
    printf("the curret memory is %d and the size of queue is %d!\n",queue->quecapacity,queue->quesize);
    return queue;
}
//析构双向队列
void delArrayQueue(arrayQueue* queue)
{
    free(queue->array);
    free(queue);
}
//从头部入队
void push_first(arrayQueue* queue,int num)
{
    if(queue->quesize == queue->quecapacity)
    {
        printf("Queue memory overflow! The expanatition has been carried!\n");
        printf("the current memory is %d\n",queue->quecapacity);
        expandQueue(queue);
    }
    queue->array[calculation(queue , queue->front - 1)] = num;
    queue->front = calculation(queue , queue->front - 1);
    queue->quesize++;
}
//从尾部入队
void push_last(arrayQueue* queue, int num)
{
    if(queue->quesize == queue->quecapacity)
    {
        printf("Queue memory overflow! The expanatition has been carried!\n");
        printf("the current memory is %d\n",queue->quecapacity);
        expandQueue(queue);
    }
    queue->array[calculation(queue , queue->front + queue->quesize)] = num;
    queue->quesize++;
}
//扩充容量
void expandQueue(arrayQueue* queue)
{
    queue->quecapacity *= queue->queexpand;
    queue->array = (int*)realloc(queue->array,sizeof(int)*queue->quecapacity);
    printf("enlager the memory successfully!\n");
    printf("the curret memory is %d\n",queue->quecapacity);
}
//双向列表索引计算
int calculation(arrayQueue* queue,int current)
{
    int rear = (current + queue->quecapacity) % queue->quecapacity;
    return rear;
}
//获取队列长度
int Qsize(arrayQueue* queue)
{
    return queue->quesize;
}
//判断队列是否为空
bool isEmpty(arrayQueue* queue)
{
    return Qsize(queue) == 0;
}
//访问对首元素
int peek_first(arrayQueue* queue)
{
    return queue->array[queue->front];
}
//访问队尾元素
int peek_last(arrayQueue* queue)
{
    return queue->array[calculation(queue,queue->front + queue->quesize) - 1];
}
//队首元素出队
int pop_first(arrayQueue* queue)
{
    int val = queue->array[queue->front];
    queue->front = calculation(queue,queue->front + 1);
    queue->quesize--;
    return val;
}
//队尾元素出队
int pop_last(arrayQueue* queue)
{
    int val = peek_last(queue);
    queue->quesize--;
    return val;
}
//队列元素打印
void printQueue(arrayQueue* queue)
{
    for(int i=0;i<queue->quesize;i++)
    {
        printf("%d\n",queue->array[calculation(queue,queue->front+i)]);
    }
}