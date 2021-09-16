//
// Created by charari on 9/14/21.
//

#ifndef BITEDU_DS_STACK_H
#define BITEDU_DS_STACK_H

#include "Common.h"

typedef struct
{
    DataType arr[DATA_LEN];
    int top;
}Stack;

void StackInit(Stack* s);
void StackPush(Stack* s, int v);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
bool StackEmpty(Stack* s);

#endif //BITEDU_DS_STACK_H
