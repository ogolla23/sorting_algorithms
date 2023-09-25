#include "sort.h"
/**
* shell_sort - The shell sort algorithm that sorts
* int in an array in assending order.
* @size: size of the array
* @array: The array.
*/
void shell_sort(int *array, size_t size)
{
size_t gap = 1;
size_t i, j;
int temp;
if (array == NULL || size < 2)
return;

while (gap < size / 3)
gap = 3 * gap + 1;

while (gap > 0)
{
for (i = gap; i < size; i++)
{
temp = array[i];
j = i;
while (j >= gap && array[j - gap] > temp)
{
array[j] = array[j - gap];
j -= gap;
}
array[j] = temp;
}
print_array(array, size);
gap /= 3;
}
}
