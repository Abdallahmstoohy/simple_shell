#include "shell.h"

/**
 * is_cmd - ohhh ohho hh ohhhh
 * @inf: var
 * @b: var
 *
 * Return: if true 1, else 0
 */
int is_cmd(info_t *inf, char *b)
{
	struct stat st;

	(void)inf;
	if (!b || stat(b, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - let me hooold both your hands and the hole in my azz
 * @e: var
 * @d: var
 * @f: var
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *e, int d, int f)
{
	static char q[1024];
	int i = 0, k = 0;

	for (k = 0, i = d; i < f; i++)
		if (e[i] != ':')
			q[k++] = e[i];
	q[k] = 0;
	return (q);
}

/**
 * find_path - city sleeps
 * @inf: var
 * @o: var
 * @cmd: var
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *inf, char *o, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!o)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(inf, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!o[i] || o[i] == ':')
		{
			path = dup_chars(o, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(inf, path))
				return (path);
			if (!o[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
