#include "shell.h"

/**
 * add_node - talk about it somwhere only we know
 * @h: var
 * @str: var
 * @num: var
 *
 * Return: size of list
 */
list_t *add_node(list_t **h, const char *str, int num)
{
	list_t *new_head;

	if (!h)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *h;
	*h = new_head;
	return (new_head);
}

/**
 * add_node_end - kisses on the forhead bnagaj'b[]
 * @h: var
 * @str: svar
 * @num: var
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **h, const char *str, int num)
{
	list_t *new_node, *node;

	if (!h)
		return (NULL);

	node = *h;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*h = new_node;
	return (new_node);
}

/**
 * print_list_str - i know you want me
 * @g: var
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *g)
{
	size_t j = 0;

	while (g)
	{
		_puts(g->str ? g->str : "(nil)");
		_puts("\n");
		g = g->next;
		j++;
	}
	return (j);
}

/**
 * delete_node_at_index - and you just can't say goodbey
 * @h: var
 * @x: var
 * Return: on succes 1 s, on failure 0
 */
int delete_node_at_index(list_t **h, unsigned int x)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!h || !*h)
		return (0);

	if (!x)
	{
		node = *h;
		*h = (*h)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *h;
	while (node)
	{
		if (i == x)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - bebeb bobobw bwbw bobo
 * @p: var
 *
 * Return: void
 */
void free_list(list_t **p)
{
	list_t *node, *next_node, *head;

	if (!p || !*p)
		return;
	head = *p;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*p = NULL;
}
