#ifndef DS_STACK_H
#define DS_STACK_H

#include "Node.h"
#define stack() Stack()
typedef struct _NODE_ Node;
typedef struct _LINKEDSTACK_ LinkedStack;
typedef struct _STACK_ stack;

/*
 * construct func
 * usage:
 *      stack ${OBJECT_NAME} = stack()
*/
stack stack();

struct _STACK_
{
    LinkedStack st;
    void(*init)(LinkedStack*);
    void(*push)(LinkedStack*, DataType);
    void(*pop)(LinkedStack*);
    DataType(*top)(LinkedStack);
    size_t(*size)(LinkedStack);
    bool(*empty)(LinkedStack);
    void(*destroy)(LinkedStack*);
};

#endif //DS_STACK_H
