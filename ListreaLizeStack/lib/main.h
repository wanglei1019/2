#ifndef MIAN_H
#define MAIN_H
typedef struct main
{
    struct main* next;
    int val;
}ListNode;


typedef struct node1
{
    ListNode* top;
    int size;
}LinkedListStack;

LinkedListStack* newLinkedListStack();
void DelLinkedListStack(LinkedListStack* nodes);
int size(LinkedListStack* nodes);
bool isEmpty(LinkedListStack* nodes);
void push(LinkedListStack* nodes, int num);
int peek(LinkedListStack* nodes);
int pop(LinkedListStack* nodes);

#endif