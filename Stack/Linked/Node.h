#ifndef DS_NODE_H
#define DS_NODE_H

#include "Common.h"

typedef struct _NODE_
{
    DataType data;
    struct _NODE_ *next;
}Node;

typedef struct _LINKEDSTACK_
{
    Node* top;
    size_t size;
}LinkedStack;

#endif //DS_NODE_H
