#ifndef DS_QUEUE_H
#define DS_QUEUE_H

#include "Node.h"
#define INIT_SIZE 10
#define INC_STEP_SIZE 5
#define queue() Queue()

typedef struct _LINKEDQUEUE_ LinkedQueue;
typedef struct _QUEUE_ queue;

/*
 * construct func
 * usage:
 *      queue ${OBJECT_NAME} = queue()
*/
queue queue();

struct _QUEUE_
{
    LinkedQueue qu;
    void(*init)(LinkedQueue*);
    void(*push)(LinkedQueue*, DataType);
    void(*pop)(LinkedQueue*);
    DataType(*front)(LinkedQueue);
    DataType(*back)(LinkedQueue);
    size_t(*size)(LinkedQueue);
    bool(*empty)(LinkedQueue);
    void(*destroy)(LinkedQueue*);
};

#endif //DS_QUEUE_H
