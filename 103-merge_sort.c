#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
* PrintArray -A function that  prints array of integers
* @array: array of values to be printed
* @start: starting index
* @end: last index
*/
void PrintArray(int *array, int start, int end)
{
int i = start;

while (i < end)
{
if (i < end - 1)
printf("%i, ", array[i]);
else
printf("%i\n", array[i]);
i++;
}
}

/**
* CopyArray - A function that copies an array.
* @src: The array.
* @beg: starting index
* @end: ending index
* @dst: array to store sorted integers
*/
void CopyArray(int *src, int beg, int end, int *dst)
{
int i;

for (i = beg; i < end; i++)
dst[i] = src[i];
}

/**
* TopDownMerge - A function that sorts subsections of an array.
* @src: The array
* @beg: left starting value
* @mid: right starting value
* @end: right ending value
* @dst: array to store sorted integers
*/
void TopDownMerge(int *src, int beg, int mid, int end, int *dst)
{
int i, j, k;

i = beg, j = mid;

printf("Merging...\n");
printf("[left]: ");
PrintArray(src, beg, mid);
printf("[right]: ");
PrintArray(src, mid, end);
for (k = beg; k < end; k++)
{
if (i < mid && (j >= end || src[i] <= src[j]))
{
dst[k] = src[i];
i++;
}
else
{
dst[k] = src[j];
j++;
}
}
printf("[Done]: ");
PrintArray(dst, beg, end);
}

/**
* TopDownSplitMerge - A function that splits an
* array into left and right then merges with TopDownMerge
* @sourceArray: The array
* @startIndex: First element.
* @endIndex: last element.
* @destinationArray: array to store sorted integers
*/
void TopDownSplitMerge(int *sourceArray, int startIndex, int endIndex,
		int *destinationArray)
{
int middleIndex;

if (endIndex - startIndex < 2)
return;
middleIndex = (endIndex + startIndex) / 2;

TopDownSplitMerge(destinationArray, startIndex, middleIndex, sourceArray);
TopDownSplitMerge(destinationArray, middleIndex, endIndex, sourceArray);
TopDownMerge(sourceArray, startIndex, middleIndex, endIndex, destinationArray);
}

/**
* merge_sort - A function that applies the merge sort algorithm
* on integers in an array.
* @array: The array.
* @size: Size of the array.
*/
void merge_sort(int *array, size_t size)
{
int *work_copy;

if (!array || size < 2)
return;

work_copy = malloc(sizeof(int) * size);
if (!work_copy)
return;

CopyArray(array, 0, size, work_copy);
TopDownSplitMerge(work_copy, 0, size, array);

free(work_copy);
}
