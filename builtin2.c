#include "shell.h"

/**
 * _myhistory -  ewyb w 5wbu
 * @inf: var
 *  Return:  0
 */
int _myhistory(info_t *inf)
{
	print_list(inf->history);
	return (0);
}

/**
 * unset_alias -  5hehnnn
 * @s: var
 *@inf: var
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *inf, char *s)
{
	char *p, c;
	int ret;

	p = _strchr(s, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(inf->alias),
		get_node_index(inf->alias, node_starts_with(inf->alias, s, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - coco waawa babbbh
 * @inf: avar
 * @s: tvar
 *
 * Return: on success 0 , on error 1
 */
int set_alias(info_t *inf, char *s)
{
	char *p;

	p = _strchr(s, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(inf, s));

	unset_alias(inf, s);
	return (add_node_end(&(inf->alias), s, 0) == NULL);
}

/**
 * print_alias - fdg ettt teg
 * @n: var
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *n)
{
	char *c = NULL, *w = NULL;

	if (n)
	{
		c = _strchr(n->str, '=');
		for (w = n->str; w <= c; w++)
			_putchar(*w);
		_putchar('\'');
		_puts(c + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - g4 ewg 4 (hfwhgan alias)
 * @inf: var
 *  Return: 0
 */
int _myalias(info_t *inf)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (inf->argc == 1)
	{
		node = inf->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; inf->argv[i]; i++)
	{
		p = _strchr(inf->argv[i], '=');
		if (p)
			set_alias(inf, inf->argv[i]);
		else
			print_alias(node_starts_with(inf->alias, inf->argv[i], '='));
	}

	return (0);
}
