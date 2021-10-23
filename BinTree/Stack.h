#ifndef DS_STACK_H
#define DS_STACK_H

#include "Tree.h"
#include "Node/SNode.h"
#define stack() Stack()

typedef struct _SNODE_ SNode, *SNodePtr;
typedef struct _STACK_ stack;

// construct func
stack stack();

struct _STACK_
{
    SNode* head;
    void(*init)(SNodePtr stack_ptr);
    void(*push)(SNodePtr stack_ptr, NodeType* src_node);
    void(*pop)(SNodePtr stack_ptr);
    NodeType*(*top)(SNodePtr stack_ptr);
    size_t(*size)(SNodePtr stack_ptr);
    bool(*empty)(SNodePtr stack_ptr);
    void(*destroy)(SNodePtr stack_ptr);
};

#endif //DS_STACK_H
