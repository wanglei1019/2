#ifndef MIAN_H
#define MAIN_H

#define MAX_SIZE 10
typedef struct k
{
    int *Array;
    int size;
}ArrayStack;


ArrayStack* newArrayStack();
void delArrayStack(ArrayStack* stack);
int size(ArrayStack* stack);
bool isEmpty(ArrayStack* stack);
void push(ArrayStack* stack, int num);
int peek(ArrayStack* stack);
int pop(ArrayStack* stack);
#endif