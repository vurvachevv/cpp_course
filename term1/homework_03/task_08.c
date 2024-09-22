#include <stdio.h>

void reverse(int array[], int size) 
{
    int temp;
    for (int i = 0; i < size / 2; i++) 
    {
        temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}

void print_array(int array[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() 
{
    int array1[] = {10, 20, 30, 40, 50, 50, 40, 30, 20, 10};
    int size1 = 5;
    reverse(array1, size1);
    print_array(array1, size1);
    
    int array2[] = {60, 20, 80, 10, 10, 80, 20, 60};
    int size2 = 4;
    reverse(array2, size2);
    print_array(array2, size2);
}
