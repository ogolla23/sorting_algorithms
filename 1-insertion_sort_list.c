#include "sort.h"
/**
* insertion_sort_list - sorts a doubly linked list in assending order.
* @list:The  Dobule linked list
* Return:Nothing.
*/
#include "sort.h"

void insertion_sort_list(listint_t **list)
{
listint_t *node, *current;

if (list == NULL || (*list)->next == NULL)
return;

for (node = (*list)->next; node != NULL; node = node->next)
{
current = node;
while (current->prev != NULL && current->prev->n > current->n)
{
current = swap_node(current, list);
print_list(*list);
}
}
}
/**
*swap_node - swap a node with its previous node.
*@node:The node
*@list: node list
*Return: return a pointer to the new node
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
