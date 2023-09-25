#include "sort.h"
/**
*swap - A function that swaps the position of two elements in an array
*@array:The array
*@item1:First element
*@item2:Second element
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
int tmp;

tmp = array[item1];
array[item1] = array[item2];
array[item2] = tmp;
}
/**
*lomuto_partition -A function thst applies the lomuto partition
*sorting in an array
*@array: The array
*@first: first element
*@last: last element
*@size: size of the array
*Return:position of the last element
*/
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
int pivot = array[last];
ssize_t i = first - 1;
ssize_t j;

for (j = first; j <= last - 1; j++)
{
if (array[j] <= pivot)
{
i++;
if (i != j)
{
swap(array, i, j);
print_array(array, size);
}
}
}
if (i + 1 != last)
{
swap(array, i + 1, last);
print_array(array, size);
}
return (i + 1);
}

/**
*qs - A function that applies the quicksort algorithm in an array.
*@array: the array
*@first: first element
*@last: last element
*@size: array of the size
*/
void qs(int *array, ssize_t first, ssize_t last, int size)
{
ssize_t position = 0;


if (first < last)
{
position = lomuto_partition(array, first, last, size);

qs(array, first, position - 1, size);
qs(array, position + 1, last, size);
}
}
/**
*quick_sort - implementing the quicksort algorithm
*@array: the array
*@size: array of the size
*/
void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
return;
qs(array, 0, size - 1, size);
}
