#include "Queue.h"

void QueueInit(Queue* q)
{
    q->rear = q->front = (Node*)malloc(sizeof(Node));
    assert(q->front);
    q->rear->data = 0;
    q->rear->next = NULL;
    q->size = 0;
}

void QueuePush(Queue* q, DataType v)
{
    assert(q->rear && q->front);
    Node* node = (Node*)malloc(sizeof(Node));
    assert(node);
    node->data = v;
    node->next = q->rear->next;
    q->rear->next = node;
    if ( node->next == NULL )
        q->front = node;
    q->size++;
}

void QueuePop(Queue* q)
{
    assert(q->rear && q->front);
    if ( QueueEmpty(q) )
        return;
    Node* p = q->rear;
    while ( p->next != q->front )
        p = p->next;
    p->next = NULL;
    free(q->front);
    q->front = p;
    q->size--;
}

DataType QueueFront(Queue* q)
{
    assert(q->front);
    return q->front->data;
}

DataType QueueBack(Queue* q)
{
    assert(q->rear);
    return q->rear->next->data;
}

size_t QueueSize(Queue* q)
{
    return q->size;
}

bool QueueEmpty(Queue* q)
{
    assert(q->rear && q->front);
    return q->front == q->rear ? true : false;
}

void QueueDestroy(Queue* q)
{
    assert(q->rear && q->front);
    Node* p = q->rear->next;
    while ( p ) {
        q->rear->next = p->next;
        free(p);
        p = q->rear->next;
    }
    free(q->rear);
    q->rear = q->front = NULL;
    q->size = 0;
}