#include "sort.h"

/**
*hoarePartition - A function that implements hoare partition sorting.
*@array: array
*@startIndex: first element in array.
*@endIndex: last element in array.
*@arraySize: size array
*Return: position of the last element.
*/
int hoarePartition(int *array, int startIndex, int endIndex, int arraySize)
{
int current = startIndex, finder = endIndex;
int pivot = array[endIndex];
int temp;
while (1)
{
while (array[current] < pivot)
{
current++;
}
while (array[finder] > pivot)
{
finder--;
}
if (current >= finder)
return (current);

temp = array[current];
array[current] = array[finder];
array[finder] = temp;

print_array(array, arraySize);
}
}

/**
*qs - A function that implements the quick sort.
*@array: array
*@first: first element in array
*@last: last element in array
*@size: array size
*/
void qs(int *array, ssize_t first, ssize_t last, int size)
{
ssize_t position = 0;

if (first < last)
{
position = hoarePartition(array, first, last, size);
qs(array, first, position - 1, size);
qs(array, position, last, size);
}
}
/**
*quick_sort_hoare - implements the quick sort algorithm.
*@array:The array
*@size: size of array.
*/
void quick_sort_hoare(int *array, size_t size)
{
if (!array || size < 2)
return;
qs(array, 0, size - 1, size);
}
