//
// Created by charari on 9/15/21.
//

#ifndef DATA_STRUCTURE_SEQLIST_H
#define DATA_STRUCTURE_SEQLIST_H

#include "Common.h"
#define INIT_SIZE 10
#define INC_STEP_SIZE 5

typedef struct
{
    DataType* base;
    size_t size;
    size_t capacity;
}SeqList;

void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);

void SeqListPrint(SeqList* ps);
void SeqListPushBack(SeqList* ps, DataType v);
void SeqListPushFront(SeqList* ps, DataType v);
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);

// 顺序表查找
size_t SeqListFind(SeqList* ps, DataType v);
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, DataType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos);
//顺序表长度
size_t SeqListLength(SeqList* ps);
//顺序表是否为空
bool SeqEmpty(SeqList* ps);

#endif //DATA_STRUCTURE_SEQLIST_H
