//
// Created by charari on 9/19/21.
//

#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H

#include "Tree.h"

typedef struct
{
    NodeType* arr;
    int top;
    size_t capacity;
}Stack;

// 栈的初始化
void StackInit(Stack* s);
// 入栈
void StackPush(Stack* s, NodeType* v);
// 出栈
void StackPop(Stack* s);
// 取栈顶
NodeType* StackTop(Stack* s);
// 栈大小
size_t StackSize(Stack* s);
// 栈空
bool StackEmpty(Stack* s);
// 栈销毁
void StackDestroy(Stack* s);

#endif //DATA_STRUCTURE_STACK_H
