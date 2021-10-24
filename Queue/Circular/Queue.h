#ifndef DS_QUEUE_H
#define DS_QUEUE_H

#include "Node.h"
#define INIT_SIZE 10
#define INC_STEP_SIZE 5
#define queue() Queue()

typedef struct _CIRQUEUE_ CirQueue;
typedef struct _QUEUE_ queue;

/*
 * construct func
 * usage:
 *      queue ${OBJECT_NAME} = queue()
*/
queue queue();

struct _QUEUE_
{
    CirQueue qu;
    void(*init)(CirQueue*);
    void(*push)(CirQueue*, DataType);
    void(*pop)(CirQueue*);
    DataType(*front)(CirQueue);
    DataType(*back)(CirQueue);
    size_t(*size)(CirQueue);
    bool(*empty)(CirQueue);
    void(*destroy)(CirQueue*);
};

#endif //DS_QUEUE_H
