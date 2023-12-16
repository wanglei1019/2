//链表从头部插入
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
typedef struct node
{
    int data;
    struct node* next;
}node1;
void insert(node1** head,int x);
void print(node1* head);
void freememory(node1* head);
int main(int arge,const char** argv)
{
    node1* head = NULL;
    printf("please input number about your wanner create linked-list\n");
    int n,x;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        printf("enter the number\n");
        scanf("%d",&x);
        insert(&head,x);
        print(head);
    }
    freememory(head);
    return 0;
}
void insert(node1** head,int x)
{
    node1* temp = (node1*)malloc(sizeof(node1));
    temp->data = x;
    temp->next = *head;
    *head = temp;
}
void print(node1* head)
{
    printf("the list is: ");
    while(head)
    {
        printf("%d ",head->data);
        // printf("%d\n",temp->next);
        head = head->next;
    }
    printf("\n");
}
void freememory(node1* head)
{
    node1* current = head;
    node1* next;
    while(current)
    {
        next = current->next;
        free(current->next);
        current = next;
    }
}