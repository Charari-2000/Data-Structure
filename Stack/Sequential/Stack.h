#ifndef DS_STACK_H
#define DS_STACK_H

#include "Node.h"
#define INIT_SIZE 10
#define INC_STEP_SIZE 5
#define stack() Stack()
typedef struct _SEQSTACK_ SeqStack;
typedef struct _STACK_ stack;

/*
 * construct func
 * usage:
 *      dclist ${OBJECT_NAME} = dclist()
*/
stack stack();

struct _STACK_
{
    SeqStack st;
    void(*init)(SeqStack*);
    void(*push)(SeqStack*, DataType);
    void(*pop)(SeqStack*);
    DataType(*top)(SeqStack);
    size_t(*size)(SeqStack);
    bool(*empty)(SeqStack);
    void(*destroy)(SeqStack*);
};

#endif //DS_STACK_H
