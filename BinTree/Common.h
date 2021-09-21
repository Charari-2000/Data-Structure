//
// Created by charari on 9/15/21.
//

#ifndef DATA_STRUCTURE_COMMON_H
#define DATA_STRUCTURE_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#define NodeType Node*
#define INIT_SIZE 10
#define INC_STEP_SIZE 5
// 1:int; 0:char
#define DataType 1
#if DataType
    #undef DataType
    #define DataType int
    #define ENDFLAG INT_MIN
#else
    #undef DataType
    #define DataType char
    #define ENDFLAG '#'
#endif


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

#endif //DATA_STRUCTURE_COMMON_H
