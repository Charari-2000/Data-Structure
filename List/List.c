#include "List.h"

Node* BuyNode(DataType v)
{
    Node* node = (Node*)malloc(sizeof(Node));
    assert(node != NULL);
    node->data = v;
    node->next = NULL;
    return node;
}

void ListInit(List* L)
{
    L->head = (Node*)malloc(sizeof(Node));
    L->head->data = 0;
    L->head->next = NULL;
    L->length = 0;
    L->tail = L->head;
}

void ListPrint(List* L)
{
    assert(L->head);
    Node* p = L->head->next;
    while ( p ) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void ListPushBack(List* L, DataType v)
{
    assert(L->head);
    Node* s = BuyNode(v);
    L->tail->next = s;
    L->tail = s;
    L->length++;
}

void ListPushFront(List* L, DataType v)
{
    assert(L->head);
    Node* s = BuyNode(v);
    s->next = L->head->next;
    L->head->next = s;
    L->length++;
}

void ListPopBack(List* L)
{
    assert(L->head);
    if ( L->length == 0 )
        return;
    Node* p = L->head;
    while ( p->next != L->tail )
        p = p->next;
    p->next = NULL;
    free(L->tail);
    L->tail = p;
    L->length--;
}

void ListPopFront(List* L)
{
    assert(L->head);
    if ( L->length == 0 )
        return;
    Node* p = L->head->next;
    L->head->next = p->next;
    if ( p == L->tail )
        L->tail = L->head;
    free(p);
    L->length--;
}

Node* ListFind(List* L, DataType v)
{
    assert(L->head);
    if ( L->length == 0 )
        return NULL;
    Node* p = L->head->next;
    while ( p != NULL && p->data != v )
        p = p->next;
    if ( !p )
        return NULL;
    return p;
}

void ListInsert(List* L, size_t pos, DataType v)
{
    assert(L->head && pos);
    if ( pos > L->length + 1 )
        return;
    Node* s = BuyNode(v);
    Node* p = L->head;
    while ( --pos )
        p = p->next;
    s->next = p->next;
    p->next = s;
    if ( p == L->tail )
        L->tail = s;
    L->length++;
}

void ListErase(List* L, size_t pos)
{
    assert(L->head && pos);
    if ( pos > L->length )
        return;
    Node* p = L->head;
    while ( --pos )
        p = p->next;
    if ( p->next == L->tail )
        L->tail = p;
    Node* post = p->next;
    p->next = post->next;
    free(post);
    L->length--;
}

void ListDestory(List* L)
{
    assert(L->head);
    Node* p = L->head->next;
    while ( p ) {
        L->head->next = p->next;
        free(p);
        p = L->head->next;
    }
    free(L->head);
    L->head = NULL;
    L->tail = NULL;
    L->length = 0;
}

size_t ListLength(List* L)
{
    assert(L->length);
    return L->length;
}

bool ListEmpty(List* L)
{
    assert(L->head);
    return L->length == 0 ? true : false;
}

static Node* Merge(Node* head1, Node* head2, Cmp cmp)
{
    Node* p1 = head1;
    Node* p2 = head2;
    Node* tmpHead = (Node*)malloc(sizeof(Node));
    Node* p = tmpHead;
    while ( p1 && p2 ) {
        if ( cmp(p1->data, p2->data) ) {
            p->next = p1;
            p1 = p1->next;
        }else {
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    }
    if ( p1 )
        p->next = p1;
    else if ( p2 )
        p->next = p2;
    p = tmpHead->next;
    free(tmpHead);
    return p;
}

void ListSort(List* L, Cmp cmp)
{
    assert(L->head);
    if ( L->length == 0 || L->length == 1 )
        return;
    Node* prev = L->head;
    Node* cur = prev->next;
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* tmp = NULL;
    for ( int step = 1; step < L->length; step <<= 1 ) {
        while ( cur ) {
            head1 = cur;
            for ( int i = step - 1; i > 0 && cur->next; i-- )
                cur = cur->next;
            head2 = cur->next;
            cur->next = NULL;
            cur = head2;
            for ( int i = step - 1; i > 0 && cur && cur->next; i-- )
                cur = cur->next;
            if ( cur ){
                tmp = cur->next;
                cur->next = NULL;
            }else
                tmp = NULL;
            prev->next = Merge(head1, head2, asc);
            while ( prev->next )
                prev = prev->next;
            prev->next = tmp;
            cur = prev->next;
            if ( !cur )
                L->tail = prev;
        }
        prev = L->head;
        cur = prev->next;
    }
}

void ListReverse(List* L)
{
    assert(L->head);
    if ( L->length == 0 || L->length == 1 )
        return;
    Node* prev = NULL;
    Node* cur = L->head->next;
    Node* post = cur->next;
    while ( cur ) {
        if ( prev == NULL )
            L->tail = cur;
        cur->next = prev;
        prev = cur;
        cur = post;
        if ( post )
            post = post->next;
    }
    L->head->next = prev;
}
