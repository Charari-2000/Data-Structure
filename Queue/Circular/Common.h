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
#define DataType int
#define INIT_SIZE 10
#define INC_STEP_SIZE 5

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

#endif //DATA_STRUCTURE_COMMON_H
