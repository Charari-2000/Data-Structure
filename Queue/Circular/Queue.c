#include "Queue.h"

void QueueInit(Queue* q)
{
    q->capacity = INIT_SIZE;
    q->arr = (DataType*)malloc(q->capacity * sizeof(DataType));
    assert(q->arr);
    q->rear = q->front = 0;
}

void QueuePush(Queue* q, DataType v)
{
    assert(q->arr);
    int size = (q->rear - q->front + (int)q->capacity) % (int)q->capacity;
    if ( size == q->capacity - 1 ) {
        q->capacity += INC_STEP_SIZE;
        DataType* new_array = (DataType*)malloc(q->capacity * sizeof(DataType));
        assert(new_array);
        for ( int i = q->front, j = 0; i != q->rear; i = (i + 1) % (int)q->capacity, j++ )
            new_array[j] = q->arr[i];
        free(q->arr);
        q->arr = new_array;
        q->front = 0;
        q->rear = size;
    }
    q->arr[q->rear] = v;
    q->rear = (q->rear + 1) % (int)q->capacity;
}

void QueuePop(Queue* q)
{
    assert(q->arr);
    if ( q->rear == q->front )
        return;
    q->front = (q->front + 1) % (int)q->capacity;
}

DataType QueueFront(Queue* q)
{
    assert(q->arr);
    return q->arr[q->front];
}

DataType QueueBack(Queue* q)
{
    assert(q->arr);
    return q->arr[(q->rear - 1 + q->capacity) % q->capacity];
}

size_t QueueSize(Queue* q)
{
    return (q->rear - q->front + q->capacity) % q->capacity;
}

bool QueueEmpty(Queue* q)
{
    return q->front == q->rear ? true : false;
}

void QueueDestroy(Queue* q)
{
    free(q->arr);
    q->arr = NULL;
    q->rear = q->front = 0;
    q->capacity = 0;
}