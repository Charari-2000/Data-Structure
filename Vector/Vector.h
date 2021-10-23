#ifndef DS_VECTOR_H
#define DS_VECTOR_H

#include "Node.h"
#define INIT_SIZE 10
#define INC_STEP_SIZE 5
#define vector() Vector()

typedef struct _SEQLIST_ SeqList;
typedef struct _VECTOR_ vector;

/*
 * construct func
 * usage:
 *      vector ${OBJECT_NAME} = vector()
*/
vector vector();

struct _VECTOR_
{
    SeqList list;
    void(*init)(SeqList*);
    void(*show)(SeqList*);
    void(*push_back)(SeqList*, DataType);
    void(*push_front)(SeqList*, DataType);
    void(*pop_back)(SeqList*);
    void(*pop_front)(SeqList*);
    void(*clear)(SeqList*);
    size_t(*find)(SeqList*, DataType);
    void(*insert)(SeqList*, size_t, DataType);
    void(*remove)(SeqList*, size_t);
    size_t(*length)(SeqList*);
    size_t(*capacity)(SeqList*);
    bool(*empty)(SeqList*);
    // Destroy List(ATTENTION: YOU MUST CALL THIS FUNCTION AFTER AN OBJECT FINISH ITS MISSON)
    void(*destroy)(SeqList*);
};

#endif //DS_VECTOR_H
