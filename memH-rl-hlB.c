#include "shell.h"

/**
* _memcpy - Copies 'ptr' to 'newptr'
* @newptr: Destin
* @ptr: Source po
* @size: Number of b
* Return: void.
*/

void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	/* Copy each byte from r' */
	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}

/**
* _realloc - Resizes mem'new_size' bytes.
* @ptr: Pointer to the resize.
* @old_size: ld size
* @new_size: New size
* Return: Pointer to memory block
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}

/**
* _reallocdp - Resizes the memo blonew_size' elem
* @ptr: Pointer to to resize
* @old_size: Old siz
* @new_size: New siz
* Return: Pointer to the newly block.
*/
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	/* If 'ptr' is NULL, malloc new_size) */
	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		newptr[i] = ptr[i];

	free(ptr);

	return (newptr);
}
