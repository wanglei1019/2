#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "main.h"
#include "happy.h"
int main(int arge, char **argv)
{
   ArrayStack* stack = newArrayStack();
   int data;
   while(scanf("%d",&data)==1)//用于检测输入数据是否为整数
   {
    push(stack,data);
   }
   printf("Data stored successfully!\n");
   printf("the length of stack is %d\n",stack->size);
}
//构造初始栈空间
ArrayStack* newArrayStack()
{
    ArrayStack* stack = (ArrayStack*)malloc(sizeof(ArrayStack));
    stack->Array = (int*)malloc(sizeof(int)*MAX_SIZE);
    stack->size = 0;
    return stack;
}
//出栈-消除栈空间
void delArrayStack(ArrayStack* stack)
{
    free(stack->Array);//是一整块内存单元
    free(stack);
}
//获取栈的长度
int size(ArrayStack* stack)
{
    return stack->size;
}
//判断栈是否为空
bool isEmpty(ArrayStack* stack)
{
    return stack->size == 0;
}
//入栈
void push(ArrayStack* stack, int num)
{
    if(stack->size == MAX_SIZE)
    {
        printf("the stack is ovweflow\n");
        return stack->size;
    }
    stack->Array[stack->size] = num;
    stack->size++;
}
//访问栈顶元素
int peek(ArrayStack* stack)
{
    int val;
    if(stack->size == 0)
    printf("the stack is empty!\n");
    return stack->Array[stack->size - 1];
}
//出栈
int pop(ArrayStack* stack)
{
    int val = peek(stack);
    stack->size--;
    return val;
}