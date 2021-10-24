#ifndef DS_COMMON_H
#define DS_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
// Changable: Set the type of List's elements here
#define DataType int

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
