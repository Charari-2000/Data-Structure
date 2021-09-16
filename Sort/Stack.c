#include "Stack.h"

void StackInit(Stack* s)
{
    s->top = -1;
}

void StackPush(Stack* s, int v)
{
    s->arr[++s->top] = v;
}

void StackPop(Stack* s)
{
    if (s->top == -1)
        return;
    s->top--;
}

DataType StackTop(Stack* s)
{
    return s->arr[s->top];
}


bool StackEmpty(Stack* s)
{
    return s->top == -1 ? true : false;
}

