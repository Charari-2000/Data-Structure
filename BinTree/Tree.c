#include "Tree.h"
#include "Stack.h"
#include "Queue.h"

static void binTreeInit(NodePtr* root, const DataType* arr, int* subs, int n)
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
    binTreeInit(&(*root)->lchild, arr, subs, n);
    binTreeInit(&(*root)->rchild, arr, subs, n);
}

void BinTreeInit(NodePtr* root, const DataType* arr, int n)
{
    int* subs = (int*)malloc(sizeof(int));
    *subs = 0;
    binTreeInit(root, arr, subs, n);
    free(subs);
}

void BinTreeInit_Iter(NodePtr* root, const DataType* arr, int n)
{
    if ( n <= 0 || arr[0] == ENDFLAG )
        return;
    stack s = stack();
    s.init(s.head);
    Node** p = root;
    int i = 0;
    while ( i < n ) {
        while ( arr[i] != ENDFLAG ) {
            *p = (Node*)malloc(sizeof(Node));
            (*p)->data = arr[i++];
            (*p)->lchild = (*p)->rchild = NULL;
            s.push(s.head, p);
            p = &(*p)->lchild;
            if ( i >= n )
                return;
        }
        i++;
        p = s.top(s.head);
        s.pop(s.head);
        p = &(*p)->rchild;
    }
    s.destroy(s.head);
}

void BinTreeInit_VLR_LVR(NodePtr* root, const DataType* VLR, const DataType* LVR, int n)
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

void BinTreeInit_LVR_LRV(NodePtr* root, const DataType* LVR, const DataType* LRV, int n)
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
    BinTreeInit_LVR_LRV(&(*root)->lchild, LVR, LRV, r);
    BinTreeInit_LVR_LRV(&(*root)->rchild, LVR + r + 1, LRV + r, n - r - 1);
}

void BinTreeInit_VLR_LVR_Iter(NodePtr* root, const DataType* VLR, const DataType* LVR, int n)
{
    if ( n <= 0 )
        return;
    stack s = stack();
    s.init(s.head);
    int index = 0;
    *root = (Node*)malloc(sizeof(Node));
    (*root)->data = VLR[0];
    (*root)->lchild = (*root)->rchild = NULL;
    s.push(s.head, root);
    for ( int i = 1; i < n; i++ ) {
        Node** p = s.top(s.head);
        if ( (*p)->data != LVR[index] ) {
            (*p)->lchild = (Node*)malloc(sizeof(Node));
            (*p)->lchild->data = VLR[i];
            (*p)->lchild->lchild = (*p)->lchild->rchild = NULL;
            s.push(s.head, &(*p)->lchild);
        }else {
            while ( !s.empty(s.head) && (*s.top(s.head))->data == LVR[index] ) {
                p = s.top(s.head);
                s.pop(s.head);
                index++;
            }
            (*p)->rchild = (Node*)malloc(sizeof(Node));
            (*p)->rchild->data = VLR[i];
            (*p)->rchild->lchild = (*p)->rchild->rchild = NULL;
            s.push(s.head, &(*p)->rchild);
        }
    }
    s.destroy(s.head);
}

void BinTreeInit_LVR_LRV_Iter(NodePtr* root, const DataType* LVR, const DataType* LRV, int n)
{
    if ( n == 0 )
        return;
    stack s = stack();
    s.init(s.head);
    int index = n - 1;
    *root = (Node*)malloc(sizeof(Node));
    (*root)->data = LRV[n - 1];
    (*root)->lchild = (*root)->rchild = NULL;
    s.push(s.head, root);
    for ( int i = 1; i < n; i++ ) {
        Node** p = s.top(s.head);
        if ( (*p)->data != LVR[index] ) {
            (*p)->rchild = (Node*)malloc(sizeof(Node));
            (*p)->rchild->data = LRV[n - i - 1];
            (*p)->rchild->lchild = (*p)->rchild->rchild = NULL;
            s.push(s.head, &(*p)->rchild);
        }else {
            while ( !s.empty(s.head) && (*s.top(s.head))->data == LVR[index] ) {
                p = s.top(s.head);
                s.pop(s.head);
                index--;
            }
            (*p)->lchild = (Node*)malloc(sizeof(Node));
            (*p)->lchild->data = LRV[n - i - 1];
            (*p)->lchild->lchild = (*p)->lchild->rchild = NULL;
            s.push(s.head, &(*p)->lchild);
        }
    }
    s.destroy(s.head);
}

void preOrder(NodePtr root)
{
    if ( root == NULL )
        return;
    printf("%d ", root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);
}

void preOrder_Iter(NodePtr root)
{
    if ( root == NULL )
        return;
    Node* p = root;
    stack s = stack();
    s.init(s.head);
    while ( p || !s.empty(s.head) ) {
        while ( p ) {
            printf("%d ", p->data);
            s.push(s.head, &p);
            p = p->lchild;
        }
        if ( !s.empty(s.head) ) {
            p = *s.top(s.head);
            s.pop(s.head);
            p = p->rchild;
        }
    }
    s.destroy(s.head);
}

void preOrder_Morris(NodePtr root)
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

void inOrder(NodePtr root)
{
    if ( root == NULL )
        return;
    inOrder(root->lchild);
    printf("%d ", root->data);
    inOrder(root->rchild);
}

void inOrder_Iter(NodePtr root)
{
    if ( root == NULL )
        return;
    Node* p = root;
    stack s = stack();
    s.init(s.head);
    while ( p || !s.empty(s.head) ) {
        while ( p ) {
            s.push(s.head, &p);
            p = p->lchild;
        }
        if ( !s.empty(s.head) ) {
            p = *s.top(s.head);
            s.pop(s.head);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
    s.destroy(s.head);
}

void inOrder_Morris(NodePtr root)
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

void postOrder(NodePtr root)
{
    if ( root == NULL )
        return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d ", root->data);
}

void postOrder_Iter(NodePtr root)
{
    if ( root == NULL )
        return;
    Node* p = root;
    Node* prev = NULL;
    stack s = stack();
    s.init(s.head);
    while ( p || !s.empty(s.head) ) {
        while ( p ) {
            s.push(s.head, &p);
            p = p->lchild;
        }
        p = *s.top(s.head);
        s.pop(s.head);
        if ( p->rchild == NULL || p->rchild == prev ) {
            printf("%d ", p->data);
            prev = p;
            p = NULL;
        }else {
            s.push(s.head, &p);
            p = p->rchild;
        }
    }
}

static void reverse(NodePtr* root)
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

static void print(NodePtr root)
{
    reverse(&root);
    Node* p = root;
    while ( p ) {
        printf("%d ", p->data);
        p = p->rchild;
    }
    reverse(&root);
}

void postOrder_Morris(NodePtr root)
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

void levelOrder(NodePtr root)
{
    if ( root == NULL )
        return;
    Node* p = NULL;
    queue q = queue();
    q.init(q.head);
    q.push(q.head, &root);
    while ( !q.empty(q.head) ) {
        p = *q.front(q.head);
        q.pop(q.head);
        printf("%d ", p->data);
        if ( !p->lchild && !p->rchild )
            continue;
        if ( p->lchild )
            q.push(q.head, &p->lchild);
        if ( p->rchild )
            q.push(q.head, &p->rchild);
    }
    q.destroy(q.head);
}

int BinTreeSize(NodePtr root)
{
    if ( root == NULL )
        return 0;
    return 1 + BinTreeSize(root->lchild) + BinTreeSize(root->rchild);
}

int BinTreeSize_Iter(NodePtr root)
{
    if ( root == NULL )
        return 0;
    int ret = 0;
    stack s = stack();
    s.init(s.head);
    Node* p = root;
    while ( p || !s.empty(s.head) ) {
        while ( p ) {
            s.push(s.head, &p);
            ret++;
            p = p->lchild;
        }
        if ( !s.empty(s.head) ) {
            p = *s.top(s.head);
            s.pop(s.head);
            p = p->rchild;
        }
    }
    s.destroy(s.head);
    return ret;
}

int BinTreeLeafSize(NodePtr root)
{
    if ( root == NULL )
        return 0;
    if ( !root->lchild && !root->rchild )
        return 1;
    return BinTreeLeafSize(root->lchild) + BinTreeLeafSize(root->rchild);
}

int BinTreeLeafSize_Iter(NodePtr root)
{
    if ( root == NULL )
        return 0;
    if ( !root->lchild && !root->rchild )
        return 1;
    int ret = 0;
    Node* p = root;
    stack s = stack();
    s.init(s.head);
    while ( p || !s.empty(s.head) ) {
        while ( p ) {
            s.push(s.head, &p);
            if ( !p->lchild && !p->rchild )
                ret++;
            p = p->lchild;
        }
        if ( !s.empty(s.head) ) {
            p = *s.top(s.head);
            s.pop(s.head);
            p = p->rchild;
        }
    }
    s.destroy(s.head);
    return ret;
}

int BinTreeLevelKSize(NodePtr root, int k)
{
    if ( root == NULL )
        return 0;
    if ( k == 1 )
        return 1;
    return BinTreeLevelKSize(root->lchild, k - 1) + BinTreeLevelKSize(root->rchild, k - 1);
}

int BinTreeLevelKSize_Iter(NodePtr root, int k)
{
    if ( root == NULL )
        return 0;
    if ( k == 1 )
        return 1;
    Node* p = NULL;
    queue q = queue();
    q.init(q.head);
    q.push(q.head, &root);
    int size = 1, n = 0;
    while ( !q.empty(q.head) ) {
        while ( size >= 1 ) {
            p = *q.front(q.head);
            q.pop(q.head);
            size--;
            if ( !p->lchild && !p->rchild )
                continue;
            if ( p->lchild ) {
                q.push(q.head, &p->lchild);
                n++;
            }
            if ( p->rchild ) {
                q.pop(q.head);
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

Node* BinTreeFind(NodePtr root, DataType v)
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

Node* BinTreeFind_Iter(NodePtr root, DataType v)
{
    if ( root == NULL )
        return NULL;
    if ( root->data == v )
        return root;
    Node* ret = root;
    stack s = stack();
    s.init(s.head);
    while ( ret || !s.empty(s.head) ) {
        while ( ret ) {
            s.push(s.head, &ret);
            if ( ret->data == v )
                return ret;
            ret = ret->lchild;
        }
        if ( !s.empty(s.head) ) {
            ret = *s.top(s.head);
            s.pop(s.head);
            ret = ret->rchild;
        }
    }
    s.destroy(s.head);
    return NULL;
}

void BinTreeDestroy(NodePtr* root)
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

void BinTreeDestroy_Iter(NodePtr* root)
{
    if ( *root == NULL )
        return;
    if ( (*root)->lchild == NULL && (*root)->rchild == NULL ) {
        free(*root);
        return;
    }
    queue q = queue();
    q.init(q.head);
    Node* p = NULL;
    q.push(q.head, root);
    while ( !q.empty(q.head) ) {
        p = *q.front(q.head);
        q.pop(q.head);
        if ( !p->lchild && !p->rchild )
            continue;
        if ( p->lchild )
            q.push(q.head, &p->lchild);
        if ( p->rchild )
            q.pop(q.head);
        p->lchild = NULL;
        p->rchild = NULL;
        free(p);
    }
}

tree tree()
{
    tree ret;
    ret.root = NULL;
    ret.init = BinTreeInit;
    ret.init_iter = BinTreeInit_Iter;
    ret.init_vlr_lvr = BinTreeInit_VLR_LVR;
    ret.init_vlr_lvr_iter = BinTreeInit_VLR_LVR_Iter;
    ret.init_lvr_lrv = BinTreeInit_LVR_LRV;
    ret.init_lvr_lrv_iter = BinTreeInit_LVR_LRV_Iter;
    ret.preorder = preOrder;
    ret.preorder_iter = preOrder_Iter;
    ret.preorder_morris = preOrder_Morris;
    ret.inorder = inOrder;
    ret.inorder_iter = inOrder_Iter;
    ret.inorder_morris = inOrder_Morris;
    ret.postorder = postOrder;
    ret.postorder_iter = postOrder_Iter;
    ret.postorder_morris = postOrder_Morris;
    ret.levelorder = levelOrder;
    ret.size = BinTreeSize;
    ret.size_iter = BinTreeSize_Iter;
    ret.leafsize = BinTreeLeafSize;
    ret.leafsize_iter = BinTreeLeafSize_Iter;
    ret.levelKSize = BinTreeLevelKSize;
    ret.levelKSize_iter = BinTreeLevelKSize_Iter;
    ret.find = BinTreeFind;
    ret.find_iter = BinTreeFind_Iter;
    ret.destroy = BinTreeDestroy;
    ret.destroy_iter = BinTreeDestroy_Iter;
    return ret;
}