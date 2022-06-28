#include "sort.h"

/**
 * swap_node - move correctly the node of position
 * @head: doble pointer to head
 * @node_a: node to change position with b
 * @node_b: node to change position with a
 *
 * Return: none
 */

void swap_node(listint_t **head, listint_t *node_a, listint_t *node_b)
{
	if (node_a->next)
		node_a->next->prev = node_b;

	if (node_b->prev)
		node_b->prev->next = node_a;

	node_b->next = node_a->next;
	node_a->prev = node_b->prev;

	node_b->prev = node_a;
	node_a->next = node_b;

	if (node_a->prev == NULL)
		*head = node_a;
}

/**
 * check_env - check environment for do swap
 * @head: doble pointer to head doble linked list
 * @node: node to evaluate
 *
 * Return: none
 */

void check_env(listint_t **head, listint_t *node)
{
	listint_t *temp = node;

	while (temp->prev)
	{
		if (temp->n < temp->prev->n)
		{
			swap_node(head, temp, temp->prev);
			print_list(*head);
		}
		else
			break;
	}

	if (temp->next)
		check_env(head, temp->next);
}

/**
 * insertion_sort_list - give order to a list
 * @list: doble pointer to doble linked list
 *
 * Return: none
 */

void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	check_env(list, (*list)->next);
}
