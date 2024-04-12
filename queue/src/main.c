#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "main.h"
#include "happy.h"
int main(int arge, char **argv)
{
    queue* queuelist = newQueueList();
    int data;
    while(scanf("%d",&data)==1)
    {
        push(queuelist,data);
    }
    printf("inputing is successful!\n");
    printf("the length of queue is %d\n",size(queuelist));
    printQueueList(queuelist);
}
//创建队列
queue* newQueueList()
{
    queue* queuelist = (queue*)malloc(sizeof(queue));//开辟队列空间
    queuelist->front = NULL;
    queuelist->rear = NULL;
    queuelist->size = 0;
    printf("queue is succeed in creating!\n");
    return queuelist;
}
//析构队列
void delQueueList(queue* queuelist)
{
    while(queuelist->front==NULL)
    {
        Listnode *tmp = queuelist->front;
        queuelist->front = queuelist->front->next;
        free(tmp);
    }
    free(queuelist);
}
//入队
void push(queue* queuelist,int num)
{
    Listnode* node = (Listnode*)malloc(sizeof(Listnode));
    node->val = num;
    node->next = NULL;
    if(queuelist->front == NULL)
    {
        queuelist->front = node;
        queuelist->rear = node;
    }
    else
    {
        queuelist->rear->next = node;
        queuelist->rear = node;
    }
    queuelist->size++;
}
//队列长度
int size(queue* queuelist)
{
    return queuelist->size;
}
//判断队列是否为空
bool isEmpty(queue* queuelist)
{
    return queuelist->size == 0;
}
//获取队列首元素
int peek(queue* queuelist)
{
    assert(size(queuelist)&&queuelist->front);
    return queuelist->front->val;
}
//出队
int pop(queue* queuelist)
{
    int num = peek(queuelist);
    Listnode* node = queuelist->front;
    queuelist->front = queuelist->front->next;
    free(node);
    queuelist->size--;
    return num;
}
//打印队列
void printQueueList(queue* queuelist)
{
    Listnode* node = queuelist->front;
    for(int i=0;i<queuelist->size;i++)
    {
        printf("%d\n",node->val);
        node = node->next;
    }
}