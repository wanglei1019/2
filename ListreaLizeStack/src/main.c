#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "main.h"
#include "happy.h"
int main(int arge, char **argv)
{
   LinkedListStack* node = newLinkedListStack();
   int data;
   while(scanf("%d",&data)==1)//用于检测输入数据是否为整数
   {
    push(node,data);
   }
   printf("Data stored successfully!\n");
   printf("the length of stack is %d\n",node->size);
}
//构造初始栈空间
LinkedListStack* newLinkedListStack()
{
    LinkedListStack* nodes = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    nodes->top = NULL;
    nodes->size = 0;
    return nodes;
}
//出栈-消除栈空间
void DelLinkedListStack(LinkedListStack* nodes)
{
    while(nodes->top)
    {
        ListNode* n = nodes->top->next;
        free(nodes->top);
        nodes->top = n;
    }
    free(nodes);
}
//获取栈的长度
int size(LinkedListStack* nodes)
{
    return nodes->size;
}
//判断栈是否为空
bool isEmpty(LinkedListStack* nodes)
{
    return nodes->size == 0;
}
//入栈
void push(LinkedListStack* nodes, int num)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = num;
    node->next = nodes->top;
    nodes->top = node;
    nodes->size++;
}
//访问栈顶元素
int peek(LinkedListStack* nodes)
{
    if(nodes->size == 0)
    printf("the stack is empty!\n");
    return nodes->top->val;
}
//出栈
int pop(LinkedListStack* nodes)
{
    int val = nodes->top->val;
    ListNode* node = nodes->top->next;
    nodes->top = nodes->top->next;
    free(node);
    nodes->size--;
    return val;
}