#include "sort.h"
#include <stdio.h>
/**
* swap - change two values in ascending or descending order
* @arr: array
* @item1: First item
* @item2:Second item
* @order: 1: ascending order, 0 descending order
*/
void swap(int arr[], int item1, int item2, int order)
{
int temp;

if (order == (arr[item1] > arr[item2]))
{
temp = arr[item1];
arr[item1] = arr[item2];
arr[item2] = temp;
}
}
/**
* merge - sort bitonic sequences recursively in both orders
* @array: array
* @startIndex: first element
* @numElement: elements number
* @sortOrder: 1: ascending order, 0 descending order
*/
void merge(int array[], int startIndex, int numElements, int sortOrder)
{
int midIndex, i;
int temp;
if (numElements > 1)
{
midIndex = numElements / 2;
for (i = startIndex; i < startIndex + midIndex; i++)
{
if ((array[i] > array[i + midIndex]) == sortOrder)
{
temp = array[i];
array[i] = array[i + midIndex];
array[i + midIndex] = temp;
}
}
merge(array, startIndex, midIndex, sortOrder);
merge(array, startIndex + midIndex, midIndex, sortOrder);
}
}

/**
* bitonicsort - A function that impliments the bitonic sort algorithm.
* @array: array
* @startIndex: first element
* @numElements: number of elements
* @sortOrder: 1: ascending order, 0 descending order
* @arraySize: array lenght
*/
void bitonicSort(int array[], int startIndex, int numElements,
		int sortOrder, int arraySize)
{
int midIndex;

if (numElements > 1)
{
printf("Merging [%i/%i] (%s):\n", numElements, arraySize,
		sortOrder >= 1 ? "UP" : "DOWN");
print_array(&array[startIndex], numElements);

midIndex = numElements / 2;
bitonicSort(array, startIndex, midIndex, 1, arraySize);
bitonicSort(array, startIndex + midIndex, midIndex, 0, arraySize);
merge(array, startIndex, numElements, sortOrder);

printf("Result [%i/%i] (%s):\n", numElements, arraySize,
		sortOrder >= 1 ? "UP" : "DOWN");
print_array(&array[startIndex], numElements);
}
}

/**
* bitonic_sort - implements the bitinic sort algorithm.
* @array:The array
* @size: size of array.
*/
void bitonic_sort(int *array, size_t size)
{
int order = 1;

if (!array || size < 2)
return;
bitonicSort(array, 0, size, order, size);
}
