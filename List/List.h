#ifndef DS_LIST_H
#define DS_LIST_H

#include "Node.h"
#define list() List()

typedef struct _NODE_ Node;
typedef struct _LINKEDLIST_ LinkedList;
typedef struct _LIST_ list;

/*
 * construct func
 * usage:
 *      list ${OBJECT_NAME} = list()
*/
list list();

struct _LIST_
{
    LinkedList list;
    void(*init)(LinkedList*);
    void(*show)(LinkedList);
    void(*push_back)(LinkedList*, DataType);
    void(*push_front)(LinkedList*, DataType);
    void(*pop_back)(LinkedList*);
    void(*pop_front)(LinkedList*);
    Node*(*find)(LinkedList, DataType);
    void(*insert)(LinkedList*, size_t pos_of_target, DataType);
    void(*remove)(LinkedList*, size_t pos_of_target);
    void(*clear)(LinkedList*);
    size_t(*size)(LinkedList);
    bool(*empty)(LinkedList);
    void(*sort)(LinkedList*, Cmp compare_rule);
    void(*reverse)(LinkedList*);
    void(*destroy)(LinkedList*);
};

#endif //DS_LIST_H
