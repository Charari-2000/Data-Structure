#ifndef DS_TNODE_H
#define DS_TNODE_H

#include "../Common.h"

struct Node
{
    DataType data;
    struct Node* lchild;
    struct Node* rchild;
};

#endif //DS_TNODE_H
