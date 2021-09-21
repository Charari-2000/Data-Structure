//
// Created by charari on 9/17/21.
//

#ifndef DATA_STRUCTURE_DLIST_H
#define DATA_STRUCTURE_DLIST_H

#include "Common.h"

typedef struct Node
{
    DataType data;
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct
{
    Node* head;
    Node* tail;
    size_t length;
}DList;

// 动态申请一个节点
Node* BuyNode(DataType v);
// 双循环链表初始化
void DListInit(DList* L);
// 双循环链表打印
void DListPrint(DList* L);
// 双循环链表尾插
void DListPushBack(DList* L, DataType v);
// 双循环链表的头插
void DListPushFront(DList* L, DataType v);
// 双循环链表的尾删
void DListPopBack(DList* L);
// 双循环链表头删
void DListPopFront(DList* L);
// 双循环链表查找
Node* DListFind(DList* L, DataType v);
// 双循环链表在pos位置插入v
void DListInsert(DList* L, size_t pos, DataType v);
// 双循环链表删除pos位置的值
void DListErase(DList* L, size_t pos);
// 双循环链表的销毁
void DListDestory(DList* L);
// 双循环链表的清除
void DListClear(DList* L);
// 双循环链表长度
size_t DListLength(DList* L);
// 双循环链表是否为空
bool DListEmpty(DList* L);
// 双循环链表排序(自底向上归并排序)
void DListSort(DList* L, Cmp cmp);
// 双循环链表反转
void DListReverse(DList* L);

#endif //DATA_STRUCTURE_DLIST_H
