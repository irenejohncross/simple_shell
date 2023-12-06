#include "shell.h"

/**
 * _memset - Fills the memory with a constant Byte
 * @s: The Pointer to a memory area
 * @b: The BYTE to fill *s with
 * @n: The amnt of bytes to be filled
 * Return: (s) A pointer to the memory AREA s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - Free a string of STRINGS
 * @pp: String of STRINGS
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - Reallocs a block of memory
 * @ptr: Points to the previously malloc block
 * @old_size: BYTE size of previous block
 * @new_size: BYTE size of new block
 *
 * Return: Points to the ol block name.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
