#ifndef MIAN_H
#define MAIN_H

typedef struct node1
{
    int* array;
    int capacity;
    int size;
    int extendRatio; 
}mylist;

void arraytolist(mylist* nums);
mylist* newMyList();
void delMyList(mylist* nums);
int MyListSzie(mylist* nums);
int MyListCapacity(mylist* nums);
int GetMyList(mylist* nums,int index);
void UpdateMyList(mylist* nums,int index,int data);
void extenCapacity(mylist* nums);
void AddMyListtail(mylist* nums,int data);
void insert(mylist* nums,int index,int data);
void AddMyListhead(mylist* nums,int data);
int removeMyList(mylist* nums, int index);
int *listtoarray(mylist* nums);


#endif