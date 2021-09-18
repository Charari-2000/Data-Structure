//
// Created by charari on 9/17/21.
//

#ifndef DATA_STRUCTURE_HEAP_H
#define DATA_STRUCTURE_HEAP_H

#include "Common.h"
#define INIT_SIZE 10
#define INC_STEP_SIZE 5

enum bigOrSmall {
    SMALL, BIG
};
typedef struct
{
    DataType* arr;
    int size;
    int capacity;
}Heap;
static Cmp order[2] = { asc, desc };

// 堆的构建
void HeapInit(Heap* hp, const DataType* a, int n, Cmp cmp);
// 堆的销毁
void HeapDestory(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, DataType x, Cmp cmp);
// 堆的删除
void HeapPop(Heap* hp, Cmp cmp);
// 取堆顶的数据
DataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
bool HeapEmpty(Heap* hp);

// TopK问题：找出N个数里面最大/最小的前K个问题。
void GetTopk(Heap* hp, const DataType* a, int n, int k, enum bigOrSmall flag);

#endif //DATA_STRUCTURE_HEAP_H
