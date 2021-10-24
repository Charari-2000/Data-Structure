#include "Stack.h"

void StackInit(LinkedStack* s)
{
    s->top = (Node*)malloc(sizeof(Node));
    assert(s->top);
    s->top->data = 0;
    s->top->next = NULL;
    s->size = 0;
}

void StackPush(LinkedStack* s, DataType v)
{
    assert(s->top);
    Node* node = (Node*)malloc(sizeof(Node));
    assert(node);
    node->data = v;
    node->next = s->top->next;
    s->top->next = node;
    s->size++;
}

bool StackEmpty(LinkedStack s)
{
    assert(s.top);
    return !s.top->next ? true : false;
}

void StackPop(LinkedStack* s)
{
    assert(s->top);
    if ( StackEmpty(*s) )
        return;
    Node* p = s->top->next;
    s->top->next = p->next;
    free(p);
    s->size--;
}

DataType StackTop(LinkedStack s)
{
    assert(s.top);
    return s.top->next->data;
}

size_t StackSize(LinkedStack s)
{
    assert(s.top);
    return s.size;
}

void StackDestroy(LinkedStack* s)
{
    assert(s->top);
    Node* p = s->top->next;
    while ( p ) {
        s->top->next = p->next;
        free(p);
        p = s->top->next;
    }
    free(s->top);
    s->top = NULL;
    s->size = 0;
}

stack stack()
{
    stack ret;
    ret.init = StackInit;
    ret.push = StackPush;
    ret.pop = StackPop;
    ret.top = StackTop;
    ret.size = StackSize;
    ret.empty = StackEmpty;
    ret.destroy = StackDestroy;
    return ret;
}