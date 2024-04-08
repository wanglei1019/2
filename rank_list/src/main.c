#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "main.h"
#include "happy.h"
int main(int arge, char **argv)
{
    mylist* list = newMyList();
    arraytolist(list);
    printHELLO_WORLD();
}
//数组数据存入
void arraytolist(mylist* nums)
{
    printf("please input your wanner store data!\n");
    int data;
    while(scanf("%d",&data)==1)
    {
        AddMyListhead(nums,data);
    }
    printf("Data stored successfully!\n");
}
//构建列表
mylist* newMyList()
{
    mylist* nums = malloc(sizeof(mylist));
    nums->capacity = 10;
    nums->size = 0;
    nums->array = (int*)malloc(sizeof(int)*nums->capacity);
    nums->extendRatio = 2;
    return nums;
}
//清空列表
void delMyList(mylist* nums)
{
    free(nums->array);
    free(nums);
}
//获取列表长度
int MyListSzie(mylist* nums)
{
    return nums->size;
}
//获取列表容量
int MyListCapacity(mylist* nums)
{
    return nums->capacity;
}
//访问元素
int GetMyList(mylist* nums,int index)
{
    assert(index>=0);
    assert(index<nums->size);
    return nums->array[index];
}
//更新元素
void UpdateMyList(mylist* nums,int index,int data)
{
    assert(index>=0);
    assert(index<nums->size);
    nums->array[index] = data;
}
//列表扩容
void extenCapacity(mylist* nums)
{
    int newcapacity = nums->capacity * nums->extendRatio;
    nums->array = (int*)realloc(nums->array,sizeof(int)*newcapacity);
}
//在尾部添加元素
void AddMyListtail(mylist* nums,int data)
{
    if(nums->size == nums->capacity)
    {
        extenCapacity(nums);
    }
    nums->array[nums->size] = data;
    nums->size++;
}
//在中间插入元素
void insert(mylist* nums,int index,int data)
{
    assert(index>=0);
    assert(index<nums->size);
    if(nums->size == nums->capacity)
    {
        extenCapacity(nums);
    }
    for(int i=nums->size;i>index;--i)
    {
        nums->array[i] = nums->array[i-1];
    }
    nums->array[index] = data;
    nums->size++;
}
//在头部添加元素
void AddMyListhead(mylist* nums,int data)
{
    if(nums->size == nums->capacity)
    {
        extenCapacity(nums);
    }
    for(int i=nums->size-1;i>0;--i)
    {
        nums->array[i] = nums->array[i-1];
    }
    nums->array[0] = data;
    nums->size++;
}
//删除元素
int removeMyList(mylist* nums, int index)
{
    assert(index>=0);
    assert(index < nums->size);
    int num = nums->array[index];
    for(int i = index;i<nums->size;i++)
    {
        nums->array[i] = nums->array[i+1];
    }
    nums->size--;
    return num;
}
//列表转数组打印
int *listtoarray(mylist* nums)
{
    return nums->array;
}