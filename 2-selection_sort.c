#include "sort.h"
/**
* selection_sort - A selection sort algorithm that sorts
* int in assending order in an array.
* @array: The array
* @size: size of the arrsy.
*/
void selection_sort(int *array, size_t size)
{
size_t i, j, min_index;
int temp;

if (array == NULL)
return;

for (i = 0; i < size - 1; i++)
{
min_index = i;
for (j = i + 1; j < size; j++)
{
if (array[j] < array[min_index])
min_index = j;
}

if (min_index != i)
{
temp = array[i];
array[i] = array[min_index];
array[min_index] = temp;
print_array(array, size);
}
}
}

