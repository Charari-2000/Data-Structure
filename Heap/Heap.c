#include "Heap.h"

static void AdjustSink(BinHeap* hp, int pos, Cmp cmp)
{
    int cur = pos;
    int child = pos * 2 + 1;
    while ( child < hp->size ) {
        if ( child + 1 < hp->size && cmp(hp->arr[child + 1], hp->arr[child]) )
            child++;
        if ( cmp(hp->arr[cur], hp->arr[child]) )
            break;
        swap(&hp->arr[cur], &hp->arr[child]);
        cur = child;
        child = cur * 2 + 1;
    }
}

static void AdjustSwim(BinHeap* hp, int pos, Cmp cmp)
{
    int cur = pos;
    int parent = (pos - 1) / 2;
    while ( cmp(hp->arr[cur], hp->arr[parent]) ) {
        swap(&hp->arr[cur], &hp->arr[parent]);
        if ( parent == 0 )
            break;
        cur = parent;
        parent = (cur - 1) / 2;
    }
}

void HeapInit(BinHeap* hp, const DataType* a, int n, Cmp cmp)
{
    hp->capacity = n > INIT_SIZE ? n : INIT_SIZE;
    hp->arr = (DataType*)malloc(hp->capacity * sizeof(DataType));
    assert(hp->arr);
    memcpy(hp->arr, a, n * sizeof(DataType));
    hp->size = n;
    int pos = (hp->size - 1) / 2;

    while ( pos >= 0 ) {
        AdjustSink(hp, pos, cmp);
        pos--;
    }
}

void HeapDestory(BinHeap* hp)
{
    assert(hp->arr);
    free(hp->arr);
    hp->arr = NULL;
    hp->capacity = 0;
    hp->size = 0;
}

void HeapPush(BinHeap* hp, DataType x, Cmp cmp)
{
    assert(hp->arr);
    if ( hp->size == hp->capacity ) {
        hp->capacity += INC_STEP_SIZE;
        DataType* new_array = (DataType*)malloc(sizeof(DataType));
        assert(new_array);
        memcpy(new_array, hp->arr, hp->size * sizeof(DataType));
        free(hp->arr);
        hp->arr = new_array;
    }
    hp->arr[hp->size++] = x;
    AdjustSwim(hp, hp->size - 1, cmp);
}

void HeapPop(BinHeap* hp, Cmp cmp)
{
    assert(hp->arr);
    if ( hp->size == 0 )
        return;
    swap(&hp->arr[0], &hp->arr[hp->size - 1]);
    hp->size--;
    AdjustSink(hp, 0, cmp);
}

DataType HeapTop(BinHeap hp)
{
    assert(hp.arr && hp.size != 0);
    return hp.arr[0];
}

size_t HeapSize(BinHeap hp)
{
    return hp.size;
}

bool HeapEmpty(BinHeap hp)
{
    return hp.size == 0 ? true : false;
}

void GetTopk(BinHeap* hp, const DataType* a, int n, int k, enum bigOrSmall flag)
{
    assert(k < n);
    HeapInit(hp, a, k, order[!flag]);
    for ( int i = k; i < n; i++ ) {
        if ( order[flag](a[i], HeapTop(*hp)) ) {
            HeapPop(hp, order[!flag]);
            HeapPush(hp, a[i], order[!flag]);
        }
    }
}

heap heap()
{
    heap ret;
    ret.init = HeapInit;
    ret.push = HeapPush;
    ret.pop = HeapPop;
    ret.top = HeapTop;
    ret.size = HeapSize;
    ret.empty = HeapEmpty;
    ret.destroy = HeapDestory;
    return ret;
}