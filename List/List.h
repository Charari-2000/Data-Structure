//
// Created by charari on 9/16/21.
//

#ifndef DATA_STRUCTURE_LIST_H
#define DATA_STRUCTURE_LIST_H

#include "Common.h"

typedef struct Node
{
    DataType data;
    struct Node* next;
}Node;

typedef struct
{
    Node* head;
    Node* tail;
    size_t length;
}List;

// 动态申请一个节点
Node* BuyNode(DataType v);
// 单链表初始化
void ListInit(List* L);
// 单链表打印
void ListPrint(List* L);
// 单链表尾插
void ListPushBack(List* L, DataType v);
// 单链表的头插
void ListPushFront(List* L, DataType v);
// 单链表的尾删
void ListPopBack(List* L);
// 单链表头删
void ListPopFront(List* L);
// 单链表查找
Node* ListFind(List* L, DataType v);
// 单链表在pos位置插入v
void ListInsert(List* L, size_t pos, DataType v);
// 单链表删除pos位置的值
void ListErase(List* L, size_t pos);
// 单链表的销毁
void ListDestory(List* L);
// 单链表的清除
void ListClear(List* L);
// 单链表长度
size_t ListLength(List* L);
// 单链表是否为空
bool ListEmpty(List* L);
// 单链表排序(自底向上归并排序)
void ListSort(List* L, Cmp cmp);
// 单链表反转
void ListReverse(List* L);

#endif //DATA_STRUCTURE_LIST_H
