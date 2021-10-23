#ifndef DS_NODE_H
#define DS_NODE_H

#include "Common.h"

typedef struct _NODE_
{
    DataType data;
    struct _NODE_ *next;
    struct _NODE_ *prev;
}Node;

struct _DOUBLE_CIRCLED_LINKEDLIST_
{
    Node* head;
    Node* tail;
    size_t length;
};

#endif //DS_NODE_H
