#include "shell.h"

/**
 * get_environ - rhv htrk fjsw 5 jr r fag
 * @inf: var.
 * Return: 0
 */
char **get_environ(info_t *inf)
{
	if (!inf->environ || inf->env_changed)
	{
		inf->environ = list_to_strings(inf->env);
		inf->env_changed = 0;
	}

	return (inf->environ);
}

/**
 * _unsetenv - ytyt jjf''a'gj gariakr
 * @inf: car
 * @v: tvary
 *  Return: 1 on delete, 0 otherwise
 */
int _unsetenv(info_t *inf, char *v)
{
	list_t *node = inf->env;
	size_t i = 0;
	char *p;

	if (!node || !v)
		return (0);

	while (node)
	{
		p = starts_with(node->str, v);
		if (p && *p == '=')
		{
			inf->env_changed = delete_node_at_index(&(inf->env), i);
			i = 0;
			node = inf->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (inf->env_changed);
}

/**
 * _setenv - malaksh daway kda enta hapaiapy keda
 * @inf: Svar
 * @v: var
 * @o: tvar
 *  Return: Always 0
 */
int _setenv(info_t *inf, char *v, char *o)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!v || !o)
		return (0);

	buf = malloc(_strlen(v) + _strlen(o) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, v);
	_strcat(buf, "=");
	_strcat(buf, o);
	node = inf->env;
	while (node)
	{
		p = starts_with(node->str, v);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			inf->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(inf->env), buf, 0);
	free(buf);
	inf->env_changed = 1;
	return (0);
}
