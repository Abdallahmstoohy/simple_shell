#include "shell.h"

/**
 * bfree - there's no blood, there' no baba
 * @p: var
 * Return: if freed 1 , else 0.
 */
int bfree(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
