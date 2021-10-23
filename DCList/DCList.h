#ifndef DS_DCLIST_H
#define DS_DCLIST_H

#include "Node.h"
#define dclist() Dclist()
typedef struct _NODE_ Node;
typedef struct _DOUBLE_CIRCLED_LINKEDLIST_ DCLinkedList;
typedef struct _DCLIST_ dclist;

/*
 * construct func
 * usage:
 *      dclist ${OBJECT_NAME} = dclist()
*/
dclist dclist();

struct _DCLIST_
{
    DCLinkedList list;
    void(*init)(DCLinkedList*);
    void(*show)(DCLinkedList);
    void(*push_back)(DCLinkedList*, DataType);
    void(*push_front)(DCLinkedList*, DataType);
    void(*pop_back)(DCLinkedList*);
    void(*pop_front)(DCLinkedList*);
    Node*(*find)(DCLinkedList, DataType);
    void(*insert)(DCLinkedList*, size_t pos_of_target, DataType);
    void(*remove)(DCLinkedList*, size_t pos_of_target);
    void(*clear)(DCLinkedList*);
    size_t(*size)(DCLinkedList);
    bool(*empty)(DCLinkedList);
    void(*sort)(DCLinkedList*, Cmp compare_rule);
    void(*reverse)(DCLinkedList*);
    void(*destroy)(DCLinkedList*);
};

#endif //DS_DCLIST_H
