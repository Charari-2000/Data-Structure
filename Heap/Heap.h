#ifndef DS_HEAP_H
#define DS_HEAP_H

#include "Node.h"
#define INIT_SIZE 10
#define INC_STEP_SIZE 5
#define heap() Heap()

typedef struct _BINHEAP_ BinHeap;
typedef struct _HEAP_ heap;

enum bigOrSmall {
    SMALL, BIG
};

/*
 * construct func
 * usage:
 *      heap ${OBJECT_NAME} = heap()
*/
heap heap();

struct _HEAP_
{
    BinHeap root;
    void(*init)(BinHeap*, const DataType*, int size_of_array, Cmp);
    void(*push)(BinHeap*, const DataType, Cmp);
    void(*pop)(BinHeap*, Cmp);
    DataType(*top)(BinHeap);
    size_t(*size)(BinHeap);
    bool(*empty)(BinHeap);
    void(*destroy)(BinHeap*);
};

static Cmp order[2] = { asc, desc }; // for TopK
// TopK: Get top K biggest/smallest numbers in an array
void GetTopk(BinHeap* hp, const DataType* a, int n, int k, enum bigOrSmall flag);

#endif //DS_HEAP_H
