#ifndef DS_QUEUE_H
#define DS_QUEUE_H

#include "Tree.h"
#include "Node/QNode.h"
#define queue() Queue()

typedef struct _QNODE_ QNode, *QNodePtr;
typedef struct _QUEUE_ queue;

// construct func
queue queue();

struct _QUEUE_
{
    QNode* head;
    void(*init)(QNodePtr queue_ptr);
    void(*push)(QNodePtr queue_ptr, NodeType* src_node);
    void(*pop)(QNodePtr queue_ptr);
    NodeType*(*front)(QNodePtr queue_ptr);
    NodeType*(*back)(QNodePtr queue_ptr);
    size_t(*size)(QNodePtr queue_ptr);
    bool(*empty)(QNodePtr queue_ptr);
    void(*destroy)(QNodePtr queue_ptr);
};

#endif //DS_QUEUE_H
