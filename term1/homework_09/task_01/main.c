#include "dynarray.h"
#include <stdio.h>

int main() 
{
    Dynarray arr;
    arr.data = malloc(5 * sizeof(int));
    arr.size = 5;
    arr.capacity = 5;
    
    for (int i = 0; i < 5; ++i) 
    {
        arr.data[i] = i + 1;
    }
    
    printf("%d\n", pop_back(&arr));
    
    resize(&arr, 8);
    
    for (size_t i = 0; i < arr.size; ++i) 
    {
        printf("%d ", arr.data[i]);
    }
    printf("\n");
    
    shrink_to_fit(&arr);
    
    Dynarray shallow = shallow_copy(&arr);
    Dynarray deep = deep_copy(&arr);
    
    destroy(&arr);
    destroy(&deep);
}
