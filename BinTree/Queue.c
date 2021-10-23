#include "Queue.h"

void QueueInit(QNodePtr q)
{
    q->capacity = INIT_SIZE;
    q->arr = (NodeType*)malloc(q->capacity * sizeof(NodeType));
    assert(q->arr);
    q->rear = q->front = 0;
}

void QueuePush(QNodePtr q, NodeType* v)
{
    assert(q->arr);
    int size = (q->rear - q->front + (int)q->capacity) % (int)q->capacity;
    if ( size == q->capacity - 1 ) {
        q->capacity += INC_STEP_SIZE;
        NodeType* new_array = (NodeType*)malloc(q->capacity * sizeof(NodeType));
        assert(new_array);
        for ( int i = q->front, j = 0; i != q->rear; i = (i + 1) % (int)q->capacity, j++ )
            new_array[j] = q->arr[i];
        free(q->arr);
        q->arr = new_array;
        q->front = 0;
        q->rear = size;
    }
    q->arr[q->rear] = *v;
    q->rear = (q->rear + 1) % (int)q->capacity;
}

void QueuePop(QNodePtr q)
{
    assert(q->arr);
    if ( q->rear == q->front )
        return;
    q->front = (q->front + 1) % (int)q->capacity;
}

NodeType* QueueFront(QNodePtr q)
{
    assert(q->arr);
    return &q->arr[q->front];
}

NodeType* QueueBack(QNodePtr q)
{
    assert(q->arr);
    return &q->arr[(q->rear - 1 + q->capacity) % q->capacity];
}

size_t QueueSize(QNodePtr q)
{
    return (q->rear - q->front + q->capacity) % q->capacity;
}

bool QueueEmpty(QNodePtr q)
{
    return q->front == q->rear ? true : false;
}

void QueueDestroy(QNodePtr q)
{
    free(q->arr);
    q->arr = NULL;
    q->rear = q->front = 0;
    q->capacity = 0;
    free(q);
}

queue queue()
{
    queue ret;
    ret.head = (QNode*)malloc(sizeof(QNode));
    ret.init = QueueInit;
    ret.push = QueuePush;
    ret.pop = QueuePop;
    ret.front = QueueFront;
    ret.back = QueueBack;
    ret.size = QueueSize;
    ret.empty = QueueEmpty;
    ret.destroy = QueueDestroy;
    return ret;
}