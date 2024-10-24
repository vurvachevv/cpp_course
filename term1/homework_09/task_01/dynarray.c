#include "dynarray.h"
#include <stdlib.h>
#include <string.h>

int pop_back(Dynarray* pd) 
{
    if (pd->size == 0) return -1;
    int value = pd->data[pd->size - 1];
    pd->size--;
    return value;
}

void resize(Dynarray* pd, size_t new_size) 
{
    if (new_size < pd->size) 
    {
        pd->size = new_size;
    } 
    else if (new_size > pd->size) 
    {
        if (new_size > pd->capacity) 
        {
            pd->capacity = new_size;
            pd->data = realloc(pd->data, pd->capacity * sizeof(int));
        }
        for (size_t i = pd->size; i < new_size; ++i) 
        {
            pd->data[i] = 0;
        }
        pd->size = new_size;
    }
}

void shrink_to_fit(Dynarray* pd) 
{
    pd->capacity = pd->size;
    pd->data = realloc(pd->data, pd->capacity * sizeof(int));
}

Dynarray shallow_copy(Dynarray* pd) 
{
    Dynarray copy = *pd;
    return copy;
}

Dynarray deep_copy(const Dynarray* pd) 
{
    Dynarray copy;
    copy.size = pd->size;
    copy.capacity = pd->capacity;
    copy.data = malloc(pd->capacity * sizeof(int));
    memcpy(copy.data, pd->data, pd->size * sizeof(int));
    return copy;
}

void destroy(Dynarray* pd) 
{
    free(pd->data);
    pd->data = NULL;
    pd->size = 0;
    pd->capacity = 0;
}
