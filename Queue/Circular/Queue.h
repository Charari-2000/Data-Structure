//
// Created by charari on 9/17/21.
//

#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

#include "Common.h"

typedef struct
{
    DataType* arr;
    int front;
    int rear;
    size_t capacity;
}Queue;

// 队列的初始化
void QueueInit(Queue* q);
// 入队
void QueuePush(Queue* q, DataType v);
// 出队
void QueuePop(Queue* q);
// 取队头
DataType QueueFront(Queue* q);
// 取队尾
DataType QueueBack(Queue* q);
// 队列大小
size_t QueueSize(Queue* q);
// 队列空
bool QueueEmpty(Queue* q);
// 队列销毁
void QueueDestroy(Queue* q);

#endif //DATA_STRUCTURE_QUEUE_H
