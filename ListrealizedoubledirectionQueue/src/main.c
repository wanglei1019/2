#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "main.h"
#include "happy.h"

int main(int argc, char **argv)
{
    int data;
    LinkListQueue* deque =  newLinkListQueue();
    printf("please input you wanner number! ctrl+d stop inputting!\n");
    while(scanf("%d",&data)==1)
    {
        push_first(deque,data);
    }
    printf("the length od queue is %d\n",deque->size);
    printQueue(deque);
    delLinkListQueue(deque);
}
/* 节点构造函数 */
DoubldeListNode* newDoubldeListNode(int num)
{
    DoubldeListNode* newnode = (DoubldeListNode*)malloc(sizeof(DoubldeListNode));
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->val = num;
    return newnode;
}
/* 节点析构函数 */
void delDoubldeListNode(DoubldeListNode* newnode)
{
    free(newnode);
}
/* 构造函数 */
LinkListQueue* newLinkListQueue()
{
    LinkListQueue* deque = (LinkListQueue*)malloc(sizeof(LinkListQueue));
    deque->front = NULL;
    deque->rear = NULL;
    deque->size = 0;
    printf("Queue is successful to creat!\n");
    return deque;
}
/* 析构函数 */
void delLinkListQueue(LinkListQueue* newqueue)
{
    int i = 0;
    while(newqueue->front!=NULL)
    {
        DoubldeListNode* tmp = newqueue->front;
        newqueue->front = newqueue->front->next;
        free(tmp);
    }
    free(newqueue);
}
/* 获取队列的长度 */
int sizeQueue(LinkListQueue* newqueue)
{
    return newqueue->size;
}
/* 判断队列是否为空 */
bool isEmpty(LinkListQueue* newqueue)
{
    return newqueue->size == 0;
}
/* 入队 */
void push(LinkListQueue* newqueue,int num,bool isfront)
{
    DoubldeListNode* node = newDoubldeListNode(num);
    if(isEmpty(newqueue))
    {
        newqueue->front = newqueue->rear = node;
    }
    else if(isfront)
    {
        newqueue->front->prev = node;
        node->next = newqueue->front;
        newqueue->front = node;
    }
    else
    {
        newqueue->rear->next = node;
        node->prev = newqueue->rear;
        newqueue->rear = node;
    }
    newqueue->size++;
}
/* 队首入队 */
void push_first(LinkListQueue* newqueue, int num)
{
    push(newqueue,num,true);
}
/* 队尾入队 */
void push_last(LinkListQueue* newqueue, int num,bool isfront)
{
    push(newqueue,num,false);
}
/* 访问队首元素 */
int peek_first(LinkListQueue* newqueue)
{
    return newqueue->front->val;
}
/* 访问队尾元素 */
int peek_last(LinkListQueue* newqueue)
{
    return newqueue->rear->val;
}
/* 出队 */
int pop(LinkListQueue* newqueue,bool isfirst)
{
    int val;
    DoubldeListNode* node;
    if(isfirst)
    {
        val = peek_first(newqueue);
        node = newqueue->front;
        newqueue->front = newqueue->front->next;
        newqueue->front->prev = NULL;
    }
    else
    {
        val = peek_last(newqueue);
        node = newqueue->rear;
        newqueue->rear = newqueue->rear->prev;
        newqueue->rear->next = NULL;
    }
    delDoubldeListNode(node);
    newqueue->size--;
    return val;
}
/* 队首出队 */
int pop_first(LinkListQueue* newqueue)
{
    return pop(newqueue,true);
}
/* 队尾出队 */
int pop_last(LinkListQueue* newqueue)
{
    return pop(newqueue,false);
}
/* 打印队列 */
void printQueue(LinkListQueue* newqueue)
{
    DoubldeListNode* node = newqueue->rear;
    for(int i = 0;i<newqueue->size;i++)
    {
        printf("%d\n",node->val);
        node = node->prev;
    }
}