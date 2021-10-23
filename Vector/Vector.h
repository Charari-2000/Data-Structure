#ifndef DS_VECTOR_H
#define DS_VECTOR_H

#include "Node.h"
#define INIT_SIZE 10
#define INC_STEP_SIZE 5
#define vector() Vector()

typedef struct _ARRAYLIST_ ArrayList;
typedef struct _VECTOR_ vector;

/*
 * construct func
 * usage:
 *      vector ${OBJECT_NAME} = vector()
*/
vector vector();

struct _VECTOR_
{
    ArrayList list;
    void(*init)(ArrayList*);
    void(*show)(ArrayList);
    void(*push_back)(ArrayList*, DataType);
    void(*push_front)(ArrayList*, DataType);
    void(*pop_back)(ArrayList*);
    void(*pop_front)(ArrayList*);
    void(*clear)(ArrayList*);
    size_t(*find)(ArrayList, DataType);
    void(*insert)(ArrayList*, size_t index_of_insertion, DataType);
    void(*remove)(ArrayList*, size_t index_of_var_will_remove);
    size_t(*size)(ArrayList);
    size_t(*capacity)(ArrayList);
    bool(*empty)(ArrayList*);
    // Destroy List(ATTENTION: YOU MUST CALL THIS FUNCTION AFTER AN OBJECT FINISH ITS MISSON)
    void(*destroy)(ArrayList*);
};

#endif //DS_VECTOR_H
