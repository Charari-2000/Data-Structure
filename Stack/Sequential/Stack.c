#include "Stack.h"

void StackInit(SeqStack* s)
{
    s->capacity = INIT_SIZE;
    s->arr = (DataType*)malloc(s->capacity * sizeof(DataType));
    s->top = -1;
}

void StackPush(SeqStack* s, DataType v)
{
    assert(s->arr);
    if ( s->top++ == s->capacity ) {
        s->capacity += INC_STEP_SIZE;
        DataType* new_array = (DataType*)malloc(sizeof(DataType));
        assert(new_array);
        memcpy(new_array, s->arr, s->top * sizeof(DataType));
        free(s->arr);
        s->arr = new_array;
    }
    s->arr[s->top] = v;
}

void StackPop(SeqStack* s)
{
    assert(s->arr);
    if ( s->top == -1 )
        return;
    s->top--;
}

DataType StackTop(SeqStack s)
{
    return s.arr[s.top];
}

size_t StackSize(SeqStack s)
{
    return s.top + 1;
}

bool StackEmpty(SeqStack s)
{
    return s.top == -1 ? true : false;
}

void StackDestroy(SeqStack* s)
{
    free(s->arr);
    s->arr = NULL;
    s->top = -1;
    s->capacity = 0;
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