#include "shell.h"

/**
 * _myenv - b rje5j bybse
 * @inf: var
 * Return:  0
 */
int _myenv(info_t *inf)
{
	print_list_str(inf->env);
	return (0);
}

/**
 * _getenv - gebr gr er gr
 * @inf: var
 * @n: var
 *
 * Return: the value
 */
char *_getenv(info_t *inf, const char *n)
{
	list_t *node = inf->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, n);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Ighew[a hboaw] v[n']
 * @inf: var
 *  Return:  0
 */
int _mysetenv(info_t *inf)
{
	if (inf->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(inf, inf->argv[1], inf->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Rbery hrjsj hello my unknown mother
 * @inf: var
 * Return: if true 0, else 1.
 */
int _myunsetenv(info_t *inf)
{
	int i;

	if (inf->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= inf->argc; i++)
		_unsetenv(inf, inf->argv[i]);

	return (0);
}

/**
 * populate_env_list - be he hked lfhwst
 * @inf: var.
 * Return:  0
 */
int populate_env_list(info_t *inf)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	inf->env = node;
	return (0);
}
