#include "list.h"

List init(size_t n) 
{
    List lst = {NULL, NULL, 0};
    for (size_t i = 0; i < n; ++i) 
    {
        push_back(&lst, 0);
    }
    return lst;
}

void print(const List* pl) 
{
    Node* cur = pl->head;
    while (cur) 
    {
    
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

void push_back(List* pl, int value) 
{
    Node* new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = pl->tail;
    
    if (pl->tail) 
    {
        pl->tail->next = new_node;
    } 
    else 
    {
        pl->head = new_node;
    }
    pl->tail = new_node;
    pl->size++;
}

int pop_back(List* pl) 
{
    if (!pl->tail) return -1;
    Node* last = pl->tail;
    int value = last->value;

    pl->tail = last->prev;
    if (pl->tail) 
    {
        pl->tail->next = NULL;
    } 
    else 
    {
        pl->head = NULL;
    }
    free(last);
    pl->size--;
    return value;
}

void push_front(List* pl, int value) 
{
    Node* new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = pl->head;
    new_node->prev = NULL;

    if (pl->head) 
    {
        pl->head->prev = new_node;
    } 
    else 
    {
        pl->tail = new_node;
    }
    pl->head = new_node;
    pl->size++;
}

int pop_front(List* pl) 
{
    if (!pl->head) return -1;
    Node* first = pl->head;
    int value = first->value;

    pl->head = first->next;
    if (pl->head)
    {
        pl->head->prev = NULL;
    } else 
    {
        pl->tail = NULL;
    }
    free(first);
    pl->size--;
    return value;
}

Node* erase(List* pl, Node* p) 
{
    if (!p) return NULL;

    if (p->prev) p->prev->next = p->next;
    if (p->next) p->next->prev = p->prev;

    if (pl->head == p) pl->head = p->next;
    if (pl->tail == p) pl->tail = p->prev;

    Node* next_node = p->next;
    free(p);
    pl->size--;
    return next_node;
}

void splice(List* plist, Node* p, List* pother) 
{
    if (!pother->head) return;

    if (pother->tail) 
    {
        if (p->prev) 
        {
            p->prev->next = pother->head;
            pother->head->prev = p->prev;
        } 
        else 
        {
            plist->head = pother->head;
        }
        p->prev = pother->tail;
        pother->tail->next = p;
    }

    plist->size += pother->size;
    pother->head = NULL;
    pother->tail = NULL;
    pother->size = 0;
}

void destroy(List* pl) 
{
    Node* cur = pl->head;
    while (cur) 
    {
        Node* next = cur->next;
        free(cur);
        cur = next;
    }
    pl->head = NULL;
    pl->tail = NULL;
    pl->size = 0;
}

void advance(Node** pp, size_t n) 
{
    for (size_t i = 0; i < n && *pp; ++i) 
    {
        *pp = (*pp)->next;
    }
}
