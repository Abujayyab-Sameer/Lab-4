#include <stdio.h>
#include <stdlib.h>

extern int sum_array(int *array, int count);

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    
    int capacity = 10;
    int count = 0;
    int *array = (int *)malloc(capacity * sizeof(int));

    while (fscanf(file, "%d", &array[count]) == 1) {
        count++;
        
        if (count >= capacity) {
            capacity *= 2;
            array = (int *)realloc(array, capacity * sizeof(int));
        }
    }
    
    fclose(file);

    int total_sum = sum_array(array, count);
    printf("Sum: %d\n", total_sum);

    free(array);
    return 0;
}