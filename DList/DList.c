#include "DList.h"

Node* BuyNode(DataType v)
{
    Node* node = (Node*)malloc(sizeof(Node));
    assert(node);
    node->data = v;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void DListInit(DList* L)
{
    L->tail = L->head = (Node*)malloc(sizeof(Node));
    assert(L->head);
    L->head->data = 0;
    L->head->next = L->head;
    L->head->prev = L->head;
    L->length = 0;
}

void DListPrint(DList* L)
{
    assert(L->head);
    Node* p = L->head->next;
    while ( p != L->head ) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void DListPushBack(DList* L, DataType v)
{
    assert(L->head);
    Node* s = BuyNode(v);
    Node* p = L->tail;
    s->next = p->next;
    s->prev = p;
    p->next = s;
    L->tail = s;
    L->head->prev = s;
    L->length++;
}

void DListPushFront(DList* L, DataType v)
{
    assert(L->head);
    Node* s = BuyNode(v);
    Node* p = L->head;
    s->next = p->next;
    s->prev = p;
    s->next->prev = s;
    p->next = s;
    if ( s->next == L->head ) {
        L->head->prev = s;
        L->tail = s;
    }
    L->length++;
}

void DListPopBack(DList* L)
{
    assert(L->head);
    if ( L->length == 0 )           // 如果没有length分量，可以使用L->head->next == L->head表达式判断队列空
        return;
    Node* p = L->tail->prev;
    p->next = L->head;
    L->head->prev = p;
    free(L->tail);
    L->tail = p;
    L->length--;
}

void DListPopFront(DList* L)
{
    assert(L->head);
    if ( L->length == 0 )
        return;
    Node* p = L->head->next;
    L->head->next = p->next;
    p->next->prev = L->head;
    if ( L->head->next == L->head )
        L->tail = L->head;
    free(p);
    L->length--;
}

Node* DListFind(DList* L, DataType v)
{
    assert(L->head);
    if ( L->length == 0 )
        return NULL;
    Node* p = L->head->next;
    while ( p != L->head && p->data != v )
        p = p->next;
    if ( p == L->head )
        return NULL;
    return p;
}

void DListInsert(DList* L, size_t pos, DataType v)
{
    assert(L->head && pos);
    if ( pos > L->length + 1 )
        return;
    Node* s = BuyNode(v);
    Node* p = L->head;
    while ( --pos )
        p = p->next;
    s->next = p->next;
    s->prev = p;
    p->next->prev = s;
    p->next = s;
    if ( p == L->tail )
        L->tail = s;
    L->length++;
}

void DListErase(DList* L, size_t pos)
{
    assert(L->head);
    if ( pos > L->length )
        return;
    Node* p = L->head;
    while ( --pos )
        p = p->next;
    Node* q = p->next;
    p->next = q->next;
    p->next->prev = p;
    if ( L->tail == q )
        L->tail = p;
    free(q);
    L->length--;
}

void DListDestory(DList* L)
{
    Node* p = L->head->next;
    while ( p != L->head ) {
        L->head->next = p->next;
        free(p);
        p = L->head->next;
    }
    free(L->head);
    L->head = L->tail = NULL;
    L->length = 0;
}

void DListClear(DList* L)
{
    Node* p = L->head->next;
    while ( p != L->head ) {
        L->head->next = p->next;
        free(p);
        p = L->head->next;
    }
    L->tail = L->head;
    L->head->prev = L->head;
    L->length = 0;
}

size_t DListLength(DList* L)
{
    return L->length;
}

bool DListEmpty(DList* L)
{
    return L->length == 0 ? true : false;
}

static Node* Merge(Node* head1, Node* head2, Cmp cmp)
{
    Node* tmpHead = (Node*)malloc(sizeof(Node));
    tmpHead->prev = NULL;
    Node* p = tmpHead;
    Node* p1 = head1;
    Node* p2 = head2;
    while ( p1 && p2 ) {
        if ( cmp(p1->data, p2->data) ) {
            p1->prev = p;
            p->next = p1;
            p1 = p1->next;
        }else {
            p2->prev = p;
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    }
    if ( p1 ) {
        p1->prev = p;
        p->next = p1;
    }
    else if ( p2 ) {
        p2->prev = p;
        p->next = p2;
    }
    p = tmpHead->next;
    free(tmpHead);
    return p;
}

void DListSort(DList* L, Cmp cmp)
{
    assert(L->head);
    if ( L->length == 0 || L->length == 1 )
        return;
    Node* pre = L->head;
    Node* cur = pre->next;
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* tmp = NULL;
    for ( int step = 1; step < L->length; step <<= 1 ) {
        while ( cur != L->head ) {
            head1 = cur;
            head1->prev = NULL;
            for ( int i = 1; i < step && cur->next != L->head; i++ )
                cur = cur->next;
            if ( cur->next != L->head ) {
                head2 = cur->next;
                head2->prev = NULL;
                cur->next = NULL;
                cur = head2;
            }else
                head2 = NULL;
            for ( int i = 1; i < step && cur->next != L->head; i++ )
                cur = cur->next;
            if ( cur != L->head ) {
                tmp = cur->next;
                tmp->prev = NULL;
                cur->next = NULL;
            }else
                tmp = L->head;
            pre->next = Merge(head1, head2, cmp);
            pre->next->prev = pre;
            while ( pre->next )
                pre = pre->next;
            pre->next = tmp;
            tmp->prev = pre;
            cur = pre->next;
            if ( cur == L->head )
                L->tail = pre;
        }
        pre = L->head;
        cur = pre->next;
    }
}

void DListReverse(DList* L)
{
    assert(L->head);
    if ( L->length == 0 || L->length == 1 )
        return;
    Node* pre = L->head;
    Node* cur = L->head->next;
    Node* pos = cur->next;
    L->head->prev = L->tail = cur;
    while ( cur != L->head ) {
        cur->next = pre;
        cur->prev = pos;
        pre = cur;
        cur = pos;
        if ( pos != L->head )
            pos = pos->next;
    }
    L->head->next = pre;
}