#ifndef DS_NODE_H
#define DS_NODE_H

#include "Common.h"

typedef struct _NODE_
{
    DataType data;
    struct _NODE_ *next;
}Node;

struct _LINKEDLIST_
{
    Node* head;
    Node* tail;
    size_t length;
};

#endif //DS_NODE_H
