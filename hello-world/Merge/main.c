#include <stdio.h>
#include <stdlib.h>

typedef struct listed 
{
    int val;
    struct listed *next;
} node;

node* mergeTwoLists(node* list1, node* list2) 
{
    if (list1 == NULL)
        return list2;
    else if (list2 == NULL)
        return list1;
    else if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list2->next, list1);
        return list2;
    }
}

node* arraytolisted(int* a, int size) 
{
    node* list = NULL;
    node* temp = NULL;
    for (int i = 0; i < size; i++) {
        node* newnode = (node*)malloc(sizeof(node));
        newnode->next = NULL;
        newnode->val = a[i];
        if (list == NULL) {
            list = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = temp->next;
        }
    }
    return list;
}

char* listToArray(node* list, int* size) 
{
    int count = 0;
    node* temp = list;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    char* array = (char*)malloc(count * sizeof(char));
    temp = list;
    for (int i = 0; i < count; i++) {
        array[i] = temp->val + '0'; //要将一个整数转换为对应的数字字符，您只需将整数值加上字符 '0' 的ASCII码。
        temp = temp->next;
    }
    
    *size = count;
    return array;
}

int main(int argc, char** argv) {
    int a[] = {3, 4, 5, 6};
    int b[] = {4, 5, 6, 7};

    node* mergedList = mergeTwoLists(arraytolisted(a, sizeof(a) / sizeof(a[0])), arraytolisted(b, sizeof(b) / sizeof(b[0])));
    
    int size;
    char* array = listToArray(mergedList, &size);
    
    printf("%.*s\n", size, array); // Print the array as string
    
    // Free dynamically allocated memory
    free(array);

    return 0;
}
