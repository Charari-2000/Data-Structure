#include "Stack.h"

void StackInit(Stack* s)
{
    s->capacity = INIT_SIZE;
    s->arr = (DataType*)malloc(s->capacity * sizeof(DataType));
    s->top = -1;
}

void StackPush(Stack* s, DataType v)
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

void StackPop(Stack* s)
{
    assert(s->arr);
    if ( s->top == -1 )
        return;
    s->top--;
}

DataType StackTop(Stack* s)
{
    return s->arr[s->top];
}

size_t StackSize(Stack* s)
{
    return s->top + 1;
}

bool StackEmpty(Stack* s)
{
    return s->top == -1 ? true : false;
}

void StackDestroy(Stack* s)
{
    free(s->arr);
    s->arr = NULL;
    s->top = -1;
    s->capacity = 0;
}