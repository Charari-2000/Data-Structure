#ifndef DS_NODE_H
#define DS_NODE_H

#include "Common.h"

typedef struct Node
{
    DataType data;
    struct Node *next;
}Node;

struct _LINKEDQUEUE_
{
    Node* front;
    Node* rear;
    size_t size;
};

#endif //DS_NODE_H
