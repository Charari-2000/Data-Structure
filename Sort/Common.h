//
// Created by charari on 9/7/21.
//

#ifndef BITEDU_DS_COMMON_H
#define BITEDU_DS_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
#include <math.h>
#define _Inline static inline
#define DataType int
#define DATA_LEN 50000

typedef bool(*Cmp)(DataType, DataType, bool);

_Inline
bool asc(DataType a, DataType b, bool isEql)
{
    if ( !isEql )
        return a < b ? true : false;
    else
        return a <= b ? true : false;
}

_Inline
bool desc(DataType a, DataType b, bool isEql)
{
    if ( !isEql )
        return a > b ? true : false;
    else
        return a >= b ? true : false;
}

_Inline
void swap(DataType* a, DataType* b)
{
    DataType tmp = *a;
    *a = *b;
    *b = tmp;
}

#endif //BITEDU_DS_COMMON_H
