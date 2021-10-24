#ifndef DS_NODE_H
#define DS_NODE_H

#include "Common.h"

struct _CIRQUEUE_
{
    DataType* arr;
    int front;
    int rear;
    size_t capacity;
};

#endif //DS_NODE_H
