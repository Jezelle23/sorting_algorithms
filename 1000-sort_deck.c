#include "deck.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
* cardval - gets value of a card
* @str:  value of the card
*
* Return: relative value of the card (0 through 12)
*/
int cardval(const char *str)
{
	int varx;
	char *array[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"};

	for (varx = 0; varx < 13; varx++)
	{
		if (strcmp(str, array[varx]) == 0)
		{
			return (varx);
		}
	}
	exit(1);
}

/**
* changenode - swaps a node
* @list: double pointer
* @node: node to be swaped
*
*/
void changenode(deck_node_t **list, deck_node_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
* sort_deck - sorts a linked list deck of cards
* @deck: double pointer to the deck to sort
*
* Return: void
*/
void sort_deck(deck_node_t **deck)
{
	char cardswap = 1, c1, c2;
	deck_node_t *current;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	current = *deck;
	while (cardswap != 0)
	{
		cardswap = 0;
		while (current->next != NULL)
		{
			c1 = cardval(current->card->value) + 13 * current->card->kind;
			c2 = cardval(current->next->card->value) + 13 * current->next->card->kind;
			if (c1 > c2)
			{
				changenode(deck, current);
				cardswap = 1;
			}
			else
				current = current->next;
		}
		if (cardswap == 0)
			break;
		cardswap = 0;
		while (current->prev != NULL)
		{
			c1 = cardval(current->card->value) + 13 * current->card->kind;
			c2 = cardval(current->prev->card->value) + 13 * current->prev->card->kind;
			if (c1 < c2)
			{
				changenode(deck, current->prev);
				cardswap = 1;
			}
			else
				current = current->prev;
		}
	}
}
