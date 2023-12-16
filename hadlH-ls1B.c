#include "shell.h"

/**
* add_sep_node_end - Adds a node at the end of list.
* @head: Pointer to the separator list.
* @sep: Separator (';', '|', or '&')
* Return: Pointer to the of the separator list.
*/
sep_list *add_sep_node_end(sep_list **head, char sep)
{
	sep_list *new, *temp;

	/* Allocate memory for the node */
	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	/* Initialize the new node char and set next to NULL*/
	new->separator = sep;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
* free_sep_list - Frees the for the separator list.
* @head: Pointer of the separator list.
*/
void free_sep_list(sep_list **head)
{
	sep_list *temp;
	sep_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
* add_line_node_end - Adds a line of the line list.
* @head: Pointer to the line list.
* @line: Pointer to the to be added.
* Return: Pointer to the line list.
*/
line_list *add_line_node_end(line_list **head, char *line)
{
	line_list *new, *temp;

	new = malloc(sizeof(line_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
* free_line_list - Frees the for the line list.
* @head: Pointer of the line list.
*/
void free_line_list(line_list **head)
{
	line_list *temp;
	line_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
