#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char** argv)
{
    printf("please input an integer number: \n");
    int n, number;
    scanf("%d", &n);
    printf("please input the number you want to find: \n");
    scanf("%d", &number);

    int* array = randomnum(n); // 保存返回的指针
    int index = find(number, array, n); // 存储查找结果

    if (index != -1) {
        printf("The number %d is found at index %d.\n", number, index);
    } else {
        printf("The number %d is not found in the array.\n", number);
    }

    free(array); // 在不再需要数组时释放内存

    return 0;
}

int* randomnum(int n)
{
    int* array = (int*)malloc(sizeof(int) * n);
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        array[i] = i;
    }
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    return array;
}

int find(int number, int* array, int n)
{
    int i = 0;
    while (i < n && array[i] != number)
    {
        i++;
    }
    if (i < n)
    {
        return i; // 找到数字，返回索引
    }
    else
    {
        return -1; // 未找到数字，返回特殊值
    }
}
