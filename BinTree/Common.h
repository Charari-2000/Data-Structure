#ifndef DS_COMMON_H
#define DS_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#define NodeType struct Node*
#define INIT_SIZE 10
#define INC_STEP_SIZE 5
// Changable: set DataType of tree and endflag(flag of null pointer)
#define DataType int
#define ENDFLAG INT_MIN

typedef bool(*Cmp)(DataType, DataType);

static inline
bool asc(DataType a, DataType b)
{
    return a <= b ? true : false;
}

static inline
bool desc(DataType a, DataType b)
{
    return a >= b ? true : false;
}

static inline
void swap(DataType* a, DataType* b)
{
    DataType tmp = *a;
    *a = *b;
    *b = tmp;
}

#endif //DS_COMMON_H
