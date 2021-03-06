#include "Vector.h"

void ArrayListInit(ArrayList* ps)
{
    ps->capacity = INIT_SIZE;
    ps->base = (DataType*)calloc(ps->capacity, sizeof(DataType));
    assert(ps->base != NULL);
    ps->size = 0;
}

void ArrayListDestory(ArrayList* ps)
{
    assert(ps->base != NULL);
    free(ps->base);
    ps->base = NULL;
    ps->capacity = 0;
    ps->size = 0;
}

void ArrayListPrint(ArrayList ps)
{
    assert(ps.base != NULL);
    for ( int i = 0; i < ps.size; i++ )
        printf("%d ", ps.base[i]);
    printf("\n");
}

void ArrayListPushBack(ArrayList* ps, DataType v)
{
    assert(ps->base != NULL);
    if ( ps->size == ps->capacity ) {
        ps->capacity += INC_STEP_SIZE;
        DataType* new_array = (DataType*)calloc(ps->capacity, sizeof(DataType));
        assert(new_array);
        memcpy(new_array, ps->base, (ps->capacity - INC_STEP_SIZE) * sizeof(DataType));
        free(ps->base);
        ps->base = new_array;
    }
    ps->base[ps->size++] = v;
}

void ArrayListPushFront(ArrayList* ps, DataType v)
{
    assert(ps->base != NULL);
    if ( ps->size != 0 ) {
        if (ps->size == ps->capacity) {
            ps->capacity += INC_STEP_SIZE;
            DataType *new_array = (DataType *)calloc(ps->capacity, sizeof(DataType));
            assert(new_array);
            memcpy(new_array, ps->base, (ps->capacity - INC_STEP_SIZE) * sizeof(DataType));
            free(ps->base);
            ps->base = new_array;
        }
        for (int subs = (int) ps->size; subs > 0; subs--)
            ps->base[subs] = ps->base[subs - 1];
    }
    ps->base[0] = v;
}

void ArrayListPopFront(ArrayList* ps)
{
    assert(ps->base != NULL);
    if ( ps->size == 0 )
        return;
    for ( int subs = 0; subs < ps->size - 1; subs++ )
        ps->base[subs] = ps->base[subs + 1];
    ps->size--;
}

void ArrayListPopBack(ArrayList* ps)
{
    assert(ps->base != NULL);
    if ( ps->size == 0 )
        return;
    ps->size--;
}

void ArrayListClear(ArrayList *ps)
{
    assert(ps->base != NULL);
    memset(ps->base, 0, ps->size * sizeof(DataType));
}

size_t ArrayListFind(ArrayList ps, DataType v)
{
    assert(ps.base != NULL);
    int subs = 0;
    for ( int i = 0; i < ps.size; i++ ) {
        if ( ps.base[i] == v )
            return i + 1;
    }
    return 0;
}

void ArrayListInsert(ArrayList* ps, size_t pos, DataType v)
{
    assert(ps->base != NULL && pos != 0);
    if ( pos > ps->size )
        return;
    if ( ps->size == ps->capacity ) {
        ps->capacity += INC_STEP_SIZE;
        DataType* new_array = (DataType*)calloc(ps->capacity, sizeof(DataType));
        assert(new_array);
        memcpy(new_array, ps->base, (ps->capacity - INC_STEP_SIZE) * sizeof(DataType));
        free(ps->base);
        ps->base = new_array;
    }
    int dest_subs = (int)pos - 1;
    for ( int subs = (int)ps->size; subs > dest_subs; subs-- )
        ps->base[subs] = ps->base[subs - 1];
    ps->base[dest_subs] = v;
    ps->size++;
}

void ArrayListErase(ArrayList* ps, size_t pos)
{
    assert(ps->base != NULL && pos != 0);
    if ( pos > ps->size )
        return;
    int dest_subs = (int)pos - 1;
    for ( int subs = dest_subs; subs < ps->size - 1; subs-- )
        ps->base[subs] = ps->base[subs + 1];
    ps->size--;
}

size_t ArrayListLength(ArrayList ps)
{
    return ps.size;
}

size_t ArrayListCapacity(ArrayList ps)
{
    return ps.capacity;
}

bool SeqEmpty(ArrayList ps)
{
    return ps.size == 0 ? true : false;
}

vector vector()
{
    vector ret;
    ret.init = ArrayListInit;
    ret.show = ArrayListPrint;
    ret.push_back = ArrayListPushBack;
    ret.push_front = ArrayListPushFront;
    ret.pop_back = ArrayListPopBack;
    ret.pop_front = ArrayListPopFront;
    ret.find = ArrayListFind;
    ret.insert = ArrayListInsert;
    ret.remove = ArrayListErase;
    ret.size = ArrayListLength;
    ret.capacity = ArrayListCapacity;
    ret.destroy = ArrayListDestory;
    return ret;
}

