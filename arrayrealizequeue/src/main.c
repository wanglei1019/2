#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "main.h"
#include "happy.h"

int main(int argc, char **argv)
{
    int data;
    queue* queuearray = newqQueueArray();
    printf("Please input your numbers, press Ctrl+D to finish:\n");
    while(scanf("%d", &data) == 1)
    {
        push(queuearray, data);
    }
    printf("Data is inputted successfully\n");
    printQueueArray(queuearray);
    DelQueueArray(queuearray);
    return 0;
}

// 创建队列
queue* newqQueueArray()
{   
    queue* queuearray = (queue*)malloc(sizeof(queue));
    queuearray->expand = 2;
    queuearray->quecapacity = 10;
    queuearray->array = (int*)malloc(sizeof(int) * queuearray->quecapacity);
    queuearray->front = 0;
    queuearray->queSzie = 0;
    queuearray->size = 0;
    printf("Queue is successfully created!\n");
    return queuearray;
}

// 析构队列
void DelQueueArray(queue* queuearray)
{
    free(queuearray->array);
    free(queuearray);
}

// 队列容量变化
void ExpandQueueArray(queue* queuearray)
{
    queuearray->quecapacity = queuearray->quecapacity * queuearray->expand;
    queuearray->array = (int*)realloc(queuearray->array, sizeof(int) * queuearray->quecapacity);
    printf("Expansion successful, current capacity: %d\n", queuearray->quecapacity);
}

// 入队
void push(queue* queuearray, int num)
{
    if(queuearray->size == queuearray->quecapacity)
    {
        printf("Array room overflow! Creating new room...\n");
        ExpandQueueArray(queuearray);
    }
    int rear = (queuearray->front + queuearray->size) % queuearray->quecapacity;
    queuearray->array[rear] = num;
    queuearray->size++;
}

// 队列长度
int Queuesize(queue* queuearray)
{
    return queuearray->size;
}

// 判断队列是否为空
bool isEmpty(queue* queuearray)
{
    return queuearray->size == 0;
}

// 获取队列首元素
int peek(queue* queuearray)
{
    assert(queuearray->size);
    return queuearray->array[queuearray->front];
}

// 出队
int pop(queue* queuearray)
{
    int val = peek(queuearray);
    queuearray->front = (queuearray->front + 1) % queuearray->quecapacity;
    queuearray->size--;
    return val;
}

// 打印队列
void printQueueArray(queue* queuearray)
{
    printf("Printing the queue:\n");
    for(int i = 0; i < queuearray->size; i++)
    {
        printf("%d\n", queuearray->array[(queuearray->front + i) % queuearray->quecapacity]);
    }
}
