#include "shell.h"

/**
 * list_len - no body else so we can be free
 * @g: var
 * Return: size of list
 */
size_t list_len(const list_t *g)
{
	size_t i = 0;

	while (g)
	{
		g = g->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - tatatatatrrrararar tar ttara t
 * @h: var
 * Return: array of strings
 */
char **list_to_strings(list_t *h)
{
	list_t *node = h;
	size_t i = list_len(h), j;
	char **strs;
	char *str;

	if (!h || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - ths is not enouguuuuuugh
 * @g: pvar
 *
 * Return: size of list
 */
size_t print_list(const list_t *g)
{
	size_t i = 0;

	while (g)
	{
		_puts(convert_number(g->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(g->str ? g->str : "(nil)");
		_puts("\n");
		g = g->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - rcorrse the lineeee
 * @n: var
 * @x: var
 * @f: vart
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *n, char *x, char f)
{
	char *p = NULL;

	while (n)
	{
		p = starts_with(n->str, x);
		if (p && ((f == -1) || (*p == f)))
			return (n);
		n = n->next;
	}
	return (NULL);
}

/**
 * get_node_index - but i'm a creep
 * @h: pvar
 * @n: var
 *
 * Return: index of n or -1
 */
ssize_t get_node_index(list_t *h, list_t *n)
{
	size_t i = 0;

	while (h)
	{
		if (h == n)
			return (i);
		h = h->next;
		i++;
	}
	return (-1);
}
