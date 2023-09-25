#include "sort.h"
#include <stdio.h>
/**
*swap_node - A function that swaps nodes.
*@node: The node
*@list: node list
*Return: pointer to the node entered
*/
listint_t *swap_node(listint_t *node, listint_t **list)
{
listint_t *prev_node = node->prev;
listint_t *next_node = node->next;

if (prev_node)
prev_node->next = next_node;
if (next_node)
next_node->prev = prev_node;

node->next = prev_node;
node->prev = prev_node->prev;

if (node->prev)
node->prev->next = node;
else
*list = node;

prev_node->prev = node;

return (node);
}
/**
*cocktail_sort_list - This is the cocktail sort algorithm that
* sorts int in assending order in a doubly linked list.
*@list: list
*/
void cocktail_sort_list(listint_t **list)
{
listint_t *node;
int swap_done;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

do {
node = *list;
swap_done = 0;
while (node->next != NULL)
{
if (node->n > node->next->n)
{
node = swap_node(node->next, list);
print_list(*list);
swap_done = 1;
}
else
{
node = node->next;
}
}
if (swap_done == 0)
break;
while (node->prev != NULL)
{
if (node->n < node->prev->n)
{
node = swap_node(node, list);
print_list(*list);
swap_done = 1;
}
else
{
node = node->prev;
}
}
} while (swap_done);
}
