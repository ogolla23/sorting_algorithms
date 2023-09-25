#include "sort.h"
#include <stdlib.h>

/**
* init_bucket_count - A function that resets bucket count to 0
* @bucket_count: array containing amounts of members for arrays in `buckets`
*/
void init_bucket_count(int *bucket_count)
{
int i;

for (i = 0; i < 10; i++)
bucket_count[i] = 0;
}

/**
* build_buckets -A function that allocates space
* for arrays to be held in `buckets`
* @buckets: array of arrays each containing sorted members of `array`
* @bucket_count: array containing amounts of members for arrays in `buckets`
*/
void build_buckets(int *bucket_count, int **buckets)
{
int *bucket;
int i = 0;

while (i < 10)
{
bucket = malloc(sizeof(int) * bucket_count[i]);
if (!bucket)
{
while (i > -1)
{
free(buckets[i]);
i--;
}
free(buckets);
exit(EXIT_FAILURE);
}
buckets[i] = bucket;
i++;
}
init_bucket_count(bucket_count);
}

/**
* find_max - A function that searches for the highest
* value in an array.
* @array: The array.
* @size: Size of the array.
* Return: largest int.
*/
int find_max(int *array, size_t size)
{
int max;
size_t i = 0;

max = array[0];
while (++i < size)
if (array[i] > max)
max = array[i];
return (max);
}

/**
* into_array - flattens buckets into array sorted by current digit place,
* then prints results and frees current buckets for next pass
* @array: The array.
* @size: size of the array.
* @buckets: array of arrays each containing sorted members of `array`
* @bucket_count: array containing amounts of members for arrays in `buckets`
*/
void into_array(int *array, size_t size, int **buckets, int *bucket_count)
{
int i, j;

for (i = 0; i < 10; i++)
{
for (j = 0; j < bucket_count[i]; j++)
{
array[j] = buckets[i][j];
}
print_array(array, size);
free(buckets[i]);
}
}
/**
* radix_sort - A function that implements the radix sort algorithm.
* @array: The array.
* @size: size of the array.
*/
void radix_sort(int *array, size_t size)
{
int **buckets;
int bucket_count[10];
int max, max_digits, pass, divisor, digit;
size_t i;

if (!array || size < 2)
return;
buckets = malloc(sizeof(int *) * 10);
if (!buckets)
exit(1);
max = find_max(array, size);
for (max_digits = 0; max > 0; max_digits++)
max /= 10;
for (pass = 0, divisor = 1; pass < max_digits; pass++, divisor *= 10)
{
init_bucket_count(bucket_count);
for (i = 0; i < size; i++)
{
digit = (array[i] / divisor) % 10;
bucket_count[digit]++;
build_buckets(bucket_count, buckets);
buckets[digit][bucket_count[digit]] = array[i];
}
into_array(array, size, buckets, bucket_count);
}
free(buckets);
}

