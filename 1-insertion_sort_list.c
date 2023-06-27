#include "sort.h"
/**
* swaplist - swaps 2 members of a list
*
* @pres: present node to be moved to left of insertion
* @insertpoint: insertion pointer
* @head: head of list
*/
void swaplist(listint_t* pres, listint_t* insertpoint, listint_t** head)
{
	listint_t* swap1 = pres->next;
	listint_t* swap2 = insertpoint->prev;

	if (swap1 != NULL)
		swap1->prev = insertpoint;
	if (swap2 != NULL)
		swap2->next = pres;
	pres->prev = swap2;
	insertpoint->next = swap1;
	pres->next = insertpoint;
	insertpoint->prev = pres;
	if (*head == insertpoint)
		*head = pres;
	print_list(*head);
}


/**
 * insertion_sort_list - sort a doubly linked list of integer
 * @list: pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *pres = NULL;
	listint_t *insertpoint = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	pres = (*list)->next;
	insertpoint = pres->prev;
	while (pres != NULL)
	{
		insertpoint = pres->prev;
		while (insertpoint != NULL && insertpoint->n > pres->n)
		{
			swaplist(pres, insertpoint, list);
			insertpoint = pres->prev;
		}
		pres = pres->next;
	}
}

