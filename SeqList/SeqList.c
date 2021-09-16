//
// Created by charari on 9/16/21.
//
#include "SeqList.h"

void SeqListInit(SeqList* ps)
{
    ps->capacity = INIT_SIZE;
    ps->base = (DataType*)calloc(ps->capacity, sizeof(DataType));
    assert(ps->base != NULL);
    ps->size = 0;
}

void SeqListDestory(SeqList* ps)
{
    assert(ps->base != NULL);
    free(ps->base);
    ps->base = NULL;
    ps->capacity = 0;
    ps->size = 0;
}

void SeqListPrint(SeqList* ps)
{
    assert(ps->base != NULL);
    for ( int i = 0; i < ps->size; i++ )
        printf("%d ", ps->base[i]);
    printf("\n");
}

void SeqListPushBack(SeqList* ps, DataType v)
{
    assert(ps->base != NULL);
    if ( ps->size == ps->capacity ) {
        ps->capacity += INC_STEP_SIZE;
        DataType* new_array = (DataType*)calloc(ps->capacity, sizeof(DataType));
        if ( new_array != NULL ) {
            memcpy(new_array, ps->base, (ps->capacity - INC_STEP_SIZE) * sizeof(DataType));
            free(ps->base);
            ps->base = new_array;
        }else
            exit(EXIT_FAILURE);
    }
    ps->base[ps->size++] = v;
}

void SeqListPushFront(SeqList* ps, DataType v)
{
    assert(ps->base != NULL);
    if ( ps->size != 0 ) {
        if (ps->size == ps->capacity) {
            ps->capacity += INC_STEP_SIZE;
            DataType *new_array = (DataType *)calloc(ps->capacity, sizeof(DataType));
            if (new_array != NULL) {
                memcpy(new_array, ps->base, (ps->capacity - INC_STEP_SIZE) * sizeof(DataType));
                free(ps->base);
                ps->base = new_array;
            }else
                exit(EXIT_FAILURE);
        }
        for (int subs = (int) ps->size; subs > 0; subs--)
            ps->base[subs] = ps->base[subs - 1];
    }
    ps->base[0] = v;
}

void SeqListPopFront(SeqList* ps)
{
    assert(ps->base != NULL);
    if ( ps->size == 0 )
        return;
    for ( int subs = 0; subs < ps->size - 1; subs++ )
        ps->base[subs] = ps->base[subs + 1];
    ps->size--;
}

void SeqListPopBack(SeqList* ps)
{
    assert(ps->base != NULL);
    if ( ps->size == 0 )
        return;
    ps->size--;
}

size_t SeqListFind(SeqList* ps, DataType v)
{
    assert(ps->base != NULL);
    int subs = 0;
    for ( int i = 0; i < ps->size; i++ ) {
        if ( ps->base[i] == v )
            return i + 1;
    }
    return 0;
}

void SeqListInsert(SeqList* ps, size_t pos, DataType v)
{
    assert(ps->base != NULL && pos != 0);
    if ( pos > ps->size )
        return;
    if ( ps->size == ps->capacity ) {
        ps->capacity += INC_STEP_SIZE;
        DataType* new_array = (DataType*)calloc(ps->capacity, sizeof(DataType));
        if ( new_array != NULL ) {
            memcpy(new_array, ps->base, (ps->capacity - INC_STEP_SIZE) * sizeof(DataType));
            free(ps->base);
            ps->base = new_array;
        }else
            exit(EXIT_FAILURE);
    }
    int dest_subs = (int)pos - 1;
    for ( int subs = (int)ps->size; subs > dest_subs; subs-- )
        ps->base[subs] = ps->base[subs - 1];
    ps->base[dest_subs] = v;
    ps->size++;
}

void SeqListErase(SeqList* ps, size_t pos)
{
    assert(ps->base != NULL && pos != 0);
    if ( pos > ps->size )
        return;
    int dest_subs = (int)pos - 1;
    for ( int subs = dest_subs; subs < ps->size - 1; subs-- )
        ps->base[subs] = ps->base[subs + 1];
    ps->size--;
}

size_t SeqListLength(SeqList* ps)
{
    assert(ps);
    return ps->size;
}

bool SeqEmpty(SeqList* ps)
{
    assert(ps);
    return ps->size == 0 ? true : false;
}
