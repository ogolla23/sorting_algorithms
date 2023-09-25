#include "sort.h"
#include <stdio.h>
/**
*_calloc - A function that implements the calloc functin.
*@numele:The number of elemets
*@size: size of each element
*Return: pointer to memory allocated.
*/
void *_calloc(unsigned int numele, unsigned int size)
{
unsigned int total_size = numele * size;
char *p;
unsigned int i;

if (numele == 0 || size == 0)
return (NULL);

p = malloc(total_size);

if (p == NULL)
return (NULL);

for (i = 0; i < total_size; i++)
p[i] = 0;

return (p);
}
/**
* counting_sort - A function that implements the
* counting sort algorithm.
* @array: The array to sort
* @size: array of the size
*/
#include <stdlib.h>

void counting_sort(int *array, size_t size)
{
size_t i;
int max_val;
int a, j, index;
int *count_arr;
if (array == NULL || size < 2)
return;

max_val = 0;
for (i = 0; i < size; i++)
if (array[i] > max_val)
max_val = array[i];

count_arr = calloc(max_val + 1, sizeof(int));

for (i = 0; i < size; i++)
count_arr[array[i]]++;

index = 0;
for (a = 0; a <= max_val; a++)
for (j = 0; j < count_arr[i]; j++)
array[index++] = a;

free(count_arr);
}

