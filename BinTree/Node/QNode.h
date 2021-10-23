#ifndef DS_QNODE_H
#define DS_QNODE_H

#include "../Common.h"

struct _QNODE_
{
    NodeType* arr;
    int front;
    int rear;
    size_t capacity;
};

#endif //DS_QNODE_H
