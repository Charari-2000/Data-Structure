#include "Queue.h"

void QueueInit(LinkedQueue* q)
{
    q->rear = q->front = (Node*)malloc(sizeof(Node));
    assert(q->front);
    q->rear->data = 0;
    q->rear->next = NULL;
    q->size = 0;
}

void QueuePush(LinkedQueue* q, DataType v)
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



bool QueueEmpty(LinkedQueue q)
{
    assert(q.rear && q.front);
    return q.front == q.rear ? true : false;
}

void QueuePop(LinkedQueue* q)
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

DataType QueueFront(LinkedQueue q)
{
    assert(q.front);
    return q.front.data;
}

DataType QueueBack(LinkedQueue q)
{
    assert(q.rear);
    return q.rear->next->data;
}

size_t QueueSize(LinkedQueue q)
{
    return q.size;
}

void QueueDestroy(LinkedQueue* q)
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

queue queue()
{
    queue ret;
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
