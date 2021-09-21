#include "Tree.h"
#include "Stack.h"
#include "Queue.h"

void BinTreeInit(Tree* root, const DataType* arr, int* subs, int n)
{
    if ( *subs >= n )
        return;
    if ( n <= 0 || arr[*subs] == ENDFLAG ) {
        (*subs)++;
        return;
    }
    *root = (Node*)malloc(sizeof(Node));
    (*root)->data = arr[*subs];
    (*root)->lchild = (*root)->rchild = NULL;
    (*subs)++;
    BinTreeInit(&(*root)->lchild, arr, subs, n);
    BinTreeInit(&(*root)->rchild, arr, subs, n);
}

void BinTreeInit_Iter(Tree* root, const DataType* arr, int n)
{
    if ( n <= 0 || arr[0] == ENDFLAG )
        return;
    Stack st;
    StackInit(&st);
    Node** p = root;
    int i = 0;
    while ( i < n ) {
        while ( arr[i] != ENDFLAG ) {
            *p = (Node*)malloc(sizeof(Node));
            (*p)->data = arr[i++];
            (*p)->lchild = (*p)->rchild = NULL;
            StackPush(&st, p);
            p = &(*p)->lchild;
            if ( i >= n )
                return;
        }
        i++;
        p = StackTop(&st);
        StackPop(&st);
        p = &(*p)->rchild;
    }
    StackDestroy(&st);
}

void BinTreeInit_VLR_LVR(Tree* root, const DataType* VLR, const DataType* LVR, int n)
{
    if ( n == 0 )
        return;
    int r = 0;
    while ( VLR[0] != LVR[r] )              // TODO: HashTable
        r++;
    *root = (Node*)malloc(sizeof(Node));
    assert(*root);
    (*root)->data = VLR[0];
    (*root)->lchild = (*root)->lchild = NULL;
    BinTreeInit_VLR_LVR(&(*root)->lchild, VLR + 1, LVR, r);
    BinTreeInit_VLR_LVR(&(*root)->rchild, VLR + r + 1, LVR + r + 1, n - r - 1);
}

void BinTreeInit_LVR_LRV(Tree* root, const DataType* LVR, const DataType* LRV, int n)
{
    if ( n == 0 )
        return;
    int r = 0;
    while ( LVR[r] != LRV[n - 1] )
        r++;
    *root = (Node*)malloc(sizeof(Node));
    assert(*root);
    (*root)->data = LRV[n - 1];
    (*root)->lchild = (*root)->rchild = NULL;
    BinTreeInit_LVR_LRV(&(*root)->lchild, LVR, LRV, r );
    BinTreeInit_LVR_LRV(&(*root)->rchild, LVR + r + 1, LRV + r, n - r - 1);
}

void BinTreeInit_VLR_LVR_Iter(Tree* root, const DataType* VLR, const DataType* LVR, int n)
{
    if ( n <= 0 )
        return;
    Stack s;
    StackInit(&s);
    int index = 0;
    *root = (Node*)malloc(sizeof(Node));
    (*root)->data = VLR[0];
    (*root)->lchild = (*root)->rchild = NULL;
    StackPush(&s, root);
    for ( int i = 1; i < n; i++ ) {
        Node** p = StackTop(&s);
        if ( (*p)->data != LVR[index] ) {
            (*p)->lchild = (Node*)malloc(sizeof(Node));
            (*p)->lchild->data = VLR[i];
            (*p)->lchild->lchild = (*p)->lchild->rchild = NULL;
            StackPush(&s, &(*p)->lchild);
        }else {
            while ( !StackEmpty(&s) && (*StackTop(&s))->data == LVR[index] ) {
                p = StackTop(&s);
                StackPop(&s);
                index++;
            }
            (*p)->rchild = (Node*)malloc(sizeof(Node));
            (*p)->rchild->data = VLR[i];
            (*p)->rchild->lchild = (*p)->rchild->rchild = NULL;
            StackPush(&s, &(*p)->rchild);
        }
    }
    StackDestroy(&s);
}

void BinTreeInit_LVR_LRV_Iter(Tree* root, const DataType* LVR, const DataType* LRV, int n)
{
    if ( n == 0 )
        return;
    Stack s;
    StackInit(&s);
    int index = n - 1;
    *root = (Node*)malloc(sizeof(Node));
    (*root)->data = LRV[n - 1];
    (*root)->lchild = (*root)->rchild = NULL;
    StackPush(&s, root);
    for ( int i = 1; i < n; i++ ) {
        Node** p = StackTop(&s);
        if ( (*p)->data != LVR[index] ) {
            (*p)->rchild = (Node*)malloc(sizeof(Node));
            (*p)->rchild->data = LRV[n - i - 1];
            (*p)->rchild->lchild = (*p)->rchild->rchild = NULL;
            StackPush(&s, &(*p)->rchild);
        }else {
            while ( !StackEmpty(&s) && (*StackTop(&s))->data == LVR[index] ) {
                p = StackTop(&s);
                StackPop(&s);
                index--;
            }
            (*p)->lchild = (Node*)malloc(sizeof(Node));
            (*p)->lchild->data = LRV[n - i - 1];
            (*p)->lchild->lchild = (*p)->lchild->rchild = NULL;
            StackPush(&s, &(*p)->lchild);
        }
    }
    StackDestroy(&s);
}

void preOrder(Tree root)
{
    if ( root == NULL )
        return;
    printf("%d ", root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);
}

void preOrder_Iter(Tree root)
{
    if ( root == NULL )
        return;
    Node* p = root;
    Stack st;
    StackInit(&st);
    while ( p || !StackEmpty(&st) ) {
        while ( p ) {
            printf("%d ", p->data);
            StackPush(&st, &p);
            p = p->lchild;
        }
        if ( !StackEmpty(&st) ) {
            p = *StackTop(&st);
            StackPop(&st);
            p = p->rchild;
        }
    }
    StackDestroy(&st);
}

void preOrder_Morris(Tree root)
{
    if ( root == NULL )
        return;
    Node* cur = root;
    Node* mostRight = NULL;
    while ( cur != NULL ) {
        mostRight = cur->lchild;
        if ( mostRight != NULL ) {
            while (mostRight->rchild != NULL && mostRight->rchild != cur)
                mostRight = mostRight->rchild;
            if (mostRight->rchild == NULL) {
                mostRight->rchild = cur;
                printf("%d ", cur->data);
                cur = cur->lchild;
                continue;
            } else
                mostRight->rchild = NULL;
        }else
            printf("%d ", cur->data);
        cur = cur->rchild;
    }
}

void inOrder(Tree root)
{
    if ( root == NULL )
        return;
    inOrder(root->lchild);
    printf("%d ", root->data);
    inOrder(root->rchild);
}

void inOrder_Iter(Tree root)
{
    if ( root == NULL )
        return;
    Node* p = root;
    Stack st;
    StackInit(&st);
    while ( p || !StackEmpty(&st) ) {
        while ( p ) {
            StackPush(&st, &p);
            p = p->lchild;
        }
        if ( !StackEmpty(&st) ) {
            p = *StackTop(&st);
            StackPop(&st);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
    StackDestroy(&st);
}

void inOrder_Morris(Tree root)
{
    if ( root == NULL )
        return;
    Node* cur = root;
    Node* mostRight = NULL;
    while ( cur != NULL ) {
        mostRight = cur->lchild;
        if ( mostRight != NULL ) {
            while ( mostRight->rchild != NULL && mostRight->rchild != cur )
                mostRight = mostRight->rchild;
            if ( mostRight->rchild == NULL ) {
                mostRight->rchild = cur;
                cur = cur->lchild;
                continue;
            }else {
                mostRight->rchild = NULL;
            }
        }
        printf("%d ", cur->data);
        cur = cur->rchild;
    }
}

void postOrder(Tree root)
{
    if ( root == NULL )
        return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d ", root->data);
}

void postOrder_Iter(Tree root)
{
    if ( root == NULL )
        return;
    Node* p = root;
    Node* prev = NULL;
    Stack st;
    StackInit(&st);
    while ( p || !StackEmpty(&st) ) {
        while ( p ) {
            StackPush(&st, &p);
            p = p->lchild;
        }
        p = *StackTop(&st);
        StackPop(&st);
        if ( p->rchild == NULL || p->rchild == prev ) {
            printf("%d ", p->data);
            prev = p;
            p = NULL;
        }else {
            StackPush(&st, &p);
            p = p->rchild;
        }
    }
}

static void reverse(Tree* root)
{
    Node* prev = NULL;
    Node* curr = *root;
    Node* post = curr->rchild;
    while ( curr ) {
        curr->rchild = prev;
        prev = curr;
        curr = post;
        if ( post )
            post = post->rchild;
    }
    *root = prev;
}

static void print(Tree root)
{
    reverse(&root);
    Node* p = root;
    while ( p ) {
        printf("%d ", p->data);
        p = p->rchild;
    }
    reverse(&root);
}

void postOrder_Morris(Tree root)
{
    if ( root == NULL )
        return;
    Node* cur = root;
    Node* mostRight = NULL;
    while ( cur != NULL ) {
        mostRight = cur->lchild;
        if ( mostRight != NULL ) {
            while ( mostRight->rchild != NULL && mostRight->rchild != cur )
                mostRight = mostRight->rchild;
            if ( mostRight->rchild == NULL ) {
                mostRight->rchild = cur;
                cur = cur->lchild;
                continue;
            }else {
                mostRight->rchild = NULL;
                print(cur->lchild);
            }
        }
        cur = cur->rchild;
    }
    print(root);
}

void levelOrder(Tree root)
{
    if ( root == NULL )
        return;
    Node* p = NULL;
    Queue q;
    QueueInit(&q);
    QueuePush(&q, &root);
    while ( !QueueEmpty(&q) ) {
        p = *QueueFront(&q);
        QueuePop(&q);
        printf("%d ", p->data);
        if ( !p->lchild && !p->rchild )
            continue;
        if ( p->lchild )
            QueuePush(&q, &p->lchild);
        if ( p->rchild )
            QueuePush(&q, &p->rchild);
    }
    QueueDestroy(&q);
}

int BinTreeSize(Tree root)
{
    if ( root == NULL )
        return 0;
    return 1 + BinTreeSize(root->lchild) + BinTreeSize(root->rchild);
}

int BinTreeSize_Iter(Tree root)
{
    if ( root == NULL )
        return 0;
    int ret = 0;
    Stack st;
    StackInit(&st);
    Node* p = root;
    while ( p || !StackEmpty(&st) ) {
        while ( p ) {
            StackPush(&st, &p);
            ret++;
            p = p->lchild;
        }
        if ( !StackEmpty(&st) ) {
            p = *StackTop(&st);
            StackPop(&st);
            p = p->rchild;
        }
    }
    StackDestroy(&st);
    return ret;
}

int BinTreeLeafSize(Tree root)
{
    if ( root == NULL )
        return 0;
    if ( !root->lchild && !root->rchild )
        return 1;
    return BinTreeLeafSize(root->lchild) + BinTreeLeafSize(root->rchild);
}

int BinTreeLeafSize_Iter(Tree root)
{
    if ( root == NULL )
        return 0;
    if ( !root->lchild && !root->rchild )
        return 1;
    int ret = 0;
    Node* p = root;
    Stack st;
    StackInit(&st);
    while ( p || !StackEmpty(&st) ) {
        while ( p ) {
            StackPush(&st, &p);
            if ( !p->lchild && !p->rchild )
                ret++;
            p = p->lchild;
        }
        if ( !StackEmpty(&st) ) {
            p = *StackTop(&st);
            StackPop(&st);
            p = p->rchild;
        }
    }
    StackDestroy(&st);
    return ret;
}

int BinTreeLevelKSize(Tree root, int k)
{
    if ( root == NULL )
        return 0;
    if ( k == 1 )
        return 1;
    return BinTreeLevelKSize(root->lchild, k - 1) + BinTreeLevelKSize(root->rchild, k - 1);
}

int BinTreeLevelKSize_Iter(Tree root, int k)
{
    if ( root == NULL )
        return 0;
    if ( k == 1 )
        return 1;
    Node* p = NULL;
    Queue q;
    QueueInit(&q);
    QueuePush(&q, &root);
    int size = 1, n = 0;
    while ( !QueueEmpty(&q) ) {
        while ( size >= 1 ) {
            p = *QueueFront(&q);
            QueuePop(&q);
            size--;
            if ( !p->lchild && !p->rchild )
                continue;
            if ( p->lchild ) {
                QueuePush(&q, &p->lchild);
                n++;
            }
            if ( p->rchild ) {
                QueuePush(&q, &p->rchild);
                n++;
            }
        }
        size = n;
        n = 0;
        k--;
        if ( k == 1 )
            return size;
    }
    return 0;
}

Node* BinTreeFind(Tree root, DataType v)
{
    if ( root == NULL )
        return NULL;
    if ( root->data == v )
        return root;
    Node* ret = BinTreeFind(root->lchild, v);
    if ( ret == NULL )
        return BinTreeFind(root->rchild, v);
    return ret;
}

Node* BinTreeFind_Iter(Tree root, DataType v)
{
    if ( root == NULL )
        return NULL;
    if ( root->data == v )
        return root;
    Node* ret = root;
    Stack st;
    StackInit(&st);
    while ( ret || !StackEmpty(&st) ) {
        while ( ret ) {
            StackPush(&st, &ret);
            if ( ret->data == v )
                return ret;
            ret = ret->lchild;
        }
        if ( !StackEmpty(&st) ) {
            ret = *StackTop(&st);
            StackPop(&st);
            ret = ret->rchild;
        }
    }
    StackDestroy(&st);
    return NULL;
}

void BinTreeDestroy(Tree* root)
{
    if ( *root == NULL )
        return;
    if ( (*root)->lchild == NULL && (*root)->rchild == NULL ) {
        free(*root);
        return;
    }
    BinTreeDestroy(&(*root)->lchild);
    BinTreeDestroy(&(*root)->rchild);
    free(*root);
}

void BinTreeDestroy_Iter(Tree* root)
{
    if ( *root == NULL )
        return;
    if ( (*root)->lchild == NULL && (*root)->rchild == NULL ) {
        free(*root);
        return;
    }
    Queue q;
    QueueInit(&q);
    Node* p = NULL;
    QueuePush(&q, root);
    while ( !QueueEmpty(&q) ) {
        p = *QueueFront(&q);
        QueuePop(&q);
        if ( !p->lchild && !p->rchild )
            continue;
        if ( p->lchild )
            QueuePush(&q, &p->lchild);
        if ( p->rchild )
            QueuePush(&q, &p->rchild);
        p->lchild = NULL;
        p->rchild = NULL;
        free(p);
    }
}