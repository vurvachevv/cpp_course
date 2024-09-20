#include <stdio.h>
#include <stdlib.h>
#define MAX_NUMBERS 10000

int main() 
{
    FILE *input_file = fopen("numbers.txt", "r");
    int numbers[MAX_NUMBERS];
    int count = 0;

    while (fscanf(input_file, "%d", &numbers[count]) != EOF) 
    {
        count++;
    }
    
    fclose(input_file);

    for (int i = 0; i < count - 1; i++) 
    {
        for (int j = i + 1; j < count; j++) 
        {
            int sum_i = 0, sum_j = 0;
            int temp_i = numbers[i], temp_j = numbers[j];

            while (temp_i > 0) 
            {
                sum_i += temp_i % 10;
                temp_i /= 10;
            }

            while (temp_j > 0) 
            {
                sum_j += temp_j % 10;
                temp_j /= 10;
            }

            if (sum_i > sum_j) 
            {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    FILE *output_file = fopen("sorted.txt", "w");
    
    for (int i = 0; i < count; i++) 
    {
        fprintf(output_file, "%d\n", numbers[i]);
    }
    fclose(output_file);
}