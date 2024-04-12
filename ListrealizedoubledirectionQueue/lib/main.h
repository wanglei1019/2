#ifndef MIAN_H
#define MAIN_H
/* 双向链表节点 */
typedef struct DoubldeListNode
{
    struct DoubldeListNode *next;
    struct DoubldeListNode *prev;
    int val;
}DoubldeListNode;

/* 基于双向链表实现的双向队列 */
typedef struct LinkListQueue
{
    DoubldeListNode *front,*rear;
    int size;
}LinkListQueue;

DoubldeListNode* newDoubldeListNode(int num);
void delDoubldeListNode(DoubldeListNode* newnode);
LinkListQueue* newLinkListQueue();
void delLinkListQueue(LinkListQueue* newqueue);
int sizeQueue(LinkListQueue* newqueue);
bool isEmpty(LinkListQueue* newqueue);
void push(LinkListQueue* newqueue,int num,bool isfront);
void push_first(LinkListQueue* newqueue, int num);
void push_last(LinkListQueue* newqueue, int num,bool isfront);
int peek_first(LinkListQueue* newqueue);
int peek_last(LinkListQueue* newqueue);
int pop(LinkListQueue* newqueue,bool isfirst);
int pop_first(LinkListQueue* newqueue);
int pop_last(LinkListQueue* newqueue);
void printQueue(LinkListQueue* newqueue);


#endif