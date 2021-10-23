#include "Stack.h"

void StackInit(SNodePtr s)
{
    s->capacity = INIT_SIZE;
    s->arr = (NodeType*)malloc(s->capacity * sizeof(NodeType));
    assert(s->arr);
    s->top = -1;
}

void StackPush(SNodePtr s, NodeType* v)
{
    assert(s->arr);
    if ( s->top++ == s->capacity ) {
        s->capacity += INC_STEP_SIZE;
        NodeType* new_array = (NodeType*)malloc(sizeof(NodeType));
        assert(new_array);
        memcpy(new_array, s->arr, s->top * sizeof(NodeType));
        free(s->arr);
        s->arr = new_array;
    }
    s->arr[s->top] = *v;
}

void StackPop(SNodePtr s)
{
    assert(s->arr);
    if ( s->top == -1 )
        return;
    s->top--;
}

NodeType* StackTop(SNodePtr s)
{
    return &s->arr[s->top];
}

size_t StackSize(SNodePtr s)
{
    return s->top + 1;
}

bool StackEmpty(SNodePtr s)
{
    return s->top == -1 ? true : false;
}

void StackDestroy(SNodePtr s)
{
    free(s->arr);
    s->arr = NULL;
    s->top = -1;
    s->capacity = 0;
    free(s);
}

stack stack()
{
    stack ret;
    ret.head = (SNode*)malloc(sizeof(SNode));
    ret.init = StackInit;
    ret.push = StackPush;
    ret.pop = StackPop;
    ret.top = StackTop;
    ret.size = StackSize;
    ret.empty = StackEmpty;
    ret.destroy = StackDestroy;
    return ret;
}