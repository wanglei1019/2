#include <stdbool.h>

#ifndef MIAN_H
#define MAIN_H
//键值对
typedef struct paris
{
    char* vals;
    int key;
}paris;
//节点
typedef struct node
{
    paris* pari;
    struct node* next;
}Node;
//哈希表
typedef struct
{
    int HASHTABLE_CABACITY;
    Node** buckets;
    int size;
    int expantion;
    double loadThres; // 触发扩容的负载因子阈值
}HashMapChaining;

HashMapChaining* newHashMapChaining();
void delHashChaining(HashMapChaining* hashMap);
int hashFunction(HashMapChaining* hashMap,const int key);
double loadFactor(HashMapChaining* hashMap);
char* getHashChainingMap(HashMapChaining* hashMap,const int key);
bool addHashChainingMap(HashMapChaining* hashMap, const int key, const char* val);
void extend(HashMapChaining* hashMap);
void delHashChainingFactor(HashMapChaining* hashMap,const int key);
void pringHashChaining(HashMapChaining* hashMap);


#endif