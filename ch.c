#include "shell.h"

/**
 * is_chain - est if  char ghaobo gaob ghh'aa'a'
 * @inf: cart
 * @b: var
 * @p: avar
 *
 * Return: if chain delimeter 1 , else 0
 */
int is_chain(info_t *inf, char *b, size_t *p)
{
	size_t j = *p;

	if (b[j] == '|' && b[j + 1] == '|')
	{
		b[j] = 0;
		j++;
		inf->cmd_buf_type = CMD_OR;
	}
	else if (b[j] == '&' && b[j + 1] == '&')
	{
		b[j] = 0;
		j++;
		inf->cmd_buf_type = CMD_AND;
	}
	else if (b[j] == ';') /* found end of this command */
	{
		b[j] = 0; /* replace semicolon with null */
		inf->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - chru only o cosokosomak last status
 * @inf: ar
 * @b: car
 * @p: avar
 * @i: var
 * @len: var
 *
 * Return: Void
 */
void check_chain(info_t *inf, char *b, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (inf->cmd_buf_type == CMD_AND)
	{
		if (inf->status)
		{
			b[i] = 0;
			j = len;
		}
	}
	if (inf->cmd_buf_type == CMD_OR)
	{
		if (!inf->status)
		{
			b[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - kokoooooko ghg
 * @inf: tvar
 *
 * Return: if replaced 1 , else 0
 */
int replace_alias(info_t *inf)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(inf->alias, inf->argv[0], '=');
		if (!node)
			return (0);
		free(inf->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		inf->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - batrga frunmcbim
 *
 * Return: if replaced 1 , else 0
 */
int replace_vars(info_t *inf)
{
	int i = 0;
	list_t *node;

	for (i = 0; inf->argv[i]; i++)
	{
		if (inf->argv[i][0] != '$' || !inf->argv[i][1])
			continue;

		if (!_strcmp(inf->argv[i], "$?"))
		{
			replace_string(&(inf->argv[i]),
				_strdup(convert_number(inf->status, 10, 0)));
			continue;
		}
		if (!_strcmp(inf->argv[i], "$$"))
		{
			replace_string(&(inf->argv[i]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(inf->env, &inf->argv[i][1], '=');
		if (node)
		{
			replace_string(&(inf->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&inf->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - rheh hah
 * @n: avr
 *
 * Return: if replaced 1 , else 0
 */
int replace_string(char **o, char *n)
{
	free(*o);
	*o = n;
	return (1);
}
