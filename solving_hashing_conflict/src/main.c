#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include <stdbool.h>

bool flag = false;

int main()
{
    int key;
    char* vals;
    HashMapChaining* hashMap = newHashMapChaining();
    while(scanf("%d->%s",&key,vals)==2)
    {
        if (addHashChainingMap(hashMap, key, vals))
        {
            printf("Adding successfully!\n");
        }
    }
    printf("completely!\n");
    pringHashChaining(hashMap);
    return 0;
}
/* 构造函数 */
HashMapChaining* newHashMapChaining()
{
    HashMapChaining* hashMap = (HashMapChaining*)malloc(sizeof(HashMapChaining));
    hashMap->HASHTABLE_CABACITY = 4;
    hashMap->size = 0;
    hashMap->expantion = 2;
    hashMap->buckets = (Node**)malloc(sizeof(Node*)*hashMap->HASHTABLE_CABACITY);
    hashMap->loadThres = 2.0/3.0;
    for(int i=0;i<hashMap->HASHTABLE_CABACITY;i++)
    {
        hashMap->buckets[i] = NULL;
    }
    printf("hashChaining is created successfully!\n");
    return hashMap;
}
/* 析构函数 */
void delHashChaining(HashMapChaining* hashMap)
{
    for(int i=0;i<hashMap->HASHTABLE_CABACITY;i++)
    {
        Node* cur = hashMap->buckets[i];
        while(cur)
        {
            Node* temp = cur;
            cur = cur->next;
            free(temp->pari->vals);
            free(temp->pari);
            free(temp);
        }
    }
    free(hashMap);
}
/* 哈希函数 */
int hashFunction(HashMapChaining* hashMap,const int key)
{
    return key%hashMap->HASHTABLE_CABACITY;
}
/* 负载因子 */
double loadFactor(HashMapChaining* hashMap)
{
    double rateFactor = (double)(hashMap->size) / (double)hashMap->HASHTABLE_CABACITY;
    if(rateFactor > hashMap->loadThres)
    {
        flag = true;
    }
    return rateFactor > hashMap->loadThres;
}
/* 查询操作 */
char* getHashChainingMap(HashMapChaining* hashMap,const int key)
{
    int index = hashFunction(hashMap,key);
    Node* cur = hashMap->buckets[index];
    while(cur)
    {
        if(cur->pari->key == key)
        {
            return cur->pari->vals;
        }
        cur = cur->next;
    }
    return "Null";
}
/* 添加操作 */
bool addHashChainingMap(HashMapChaining* hashMap, const int key, const char* val)
{
    int index = hashFunction(hashMap, key);
    if (loadFactor(hashMap))
    {
        extend(hashMap);
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        return false; // 内存分配失败
    }
    newNode->pari = (paris*)malloc(sizeof(paris));
    if (!newNode->pari) {
        free(newNode); // 释放已分配的节点内存
        return false; // 内存分配失败
    }
    newNode->pari->key = key;
    newNode->pari->vals = (char*)malloc(strlen(val) + 1);
    if (!newNode->pari->vals) {
        free(newNode->pari); // 释放已分配的键值对内存
        free(newNode); // 释放已分配的节点内存
        return false; // 内存分配失败
    }
    strcpy(newNode->pari->vals, val);
    newNode->next = NULL;
    if (hashMap->buckets[index] == NULL)
    {
        hashMap->buckets[index] = newNode;
    }
    else
    {
        Node* cur = hashMap->buckets[index];
        hashMap->buckets[index] = newNode; // 新节点作为头节点
        newNode->next = cur;
    }
    hashMap->size++;
    return true; // 添加成功
}
/* 扩容哈希表 */
void extend(HashMapChaining* hashMap)
{
    int oldcapacity = hashMap->HASHTABLE_CABACITY;
    Node** oldHashchaining = hashMap->buckets;
    hashMap->HASHTABLE_CABACITY *= hashMap->expantion;
    hashMap->buckets = (Node**)malloc(sizeof(Node*) * hashMap->HASHTABLE_CABACITY);
    for(int i=0;i< hashMap->HASHTABLE_CABACITY;i++)
    {
        hashMap->buckets[i] = NULL;
    }
    hashMap->size = 0;
    for(int j=0;j<oldcapacity;j++)
    {
        Node* cur = oldHashchaining[j];
        while(cur)
        {
            Node* temp = cur;
            addHashChainingMap(hashMap,cur->pari->key,cur->pari->vals);
            cur = cur->next;
            free(temp->pari->vals);
            free(temp->pari);
            free(temp);
        }
    }
    free(oldHashchaining);
    flag = false;
    printf("extending the hashchaining successfully!\n");
}
/* 删除操作 */
void delHashChainingFactor(HashMapChaining* hashMap,const int key)
{
    int index = hashFunction(hashMap,key);
    Node* cur = hashMap->buckets[index];
    Node *pre = NULL;
    while (cur)
    {
        if(cur->pari->key == key)
        {
            if(pre)
            {
                pre->next = cur->next;
            }
            else
            {
                hashMap->buckets[index] = cur->next;
            }
            free(cur->pari->vals);
            free(cur->pari);
            free(cur);
            return ;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
    hashMap->size--;
}
/* 打印哈希表 */
void pringHashChaining(HashMapChaining* hashMap)
{
    Node** cur = hashMap->buckets;
    for(int i=0;i<hashMap->HASHTABLE_CABACITY;i++)
    {
        Node* temp = cur[i];
        while(temp)
        {
            printf("the buckets [%d] has these key -> values:\n",i);
            printf("\n%d -> %s\n",temp->pari->key,temp->pari->vals);
            temp = temp->next;
        }
    }
    delHashChaining(hashMap);
}