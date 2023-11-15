#include "shell.h"

/**
 * input_buf - aha iftaha maha coha
 * @inf: pvar
 * @b: var
 * @l: var
 * Return: bytes
 */
ssize_t input_buf(info_t *inf, char **b, size_t *l)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*l)
	{
		free(*b);
		*b = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(b, &len_p, stdin);
#else
		r = _getline(inf, b, &len_p);
#endif
		if (r > 0)
		{
			if ((*b)[r - 1] == '\n')
			{
				(*b)[r - 1] = '\0';
				r--;
			}
			inf->linecount_flag = 1;
			remove_comments(*b);
			build_history_list(inf, *b, inf->histcount++);
			{
				*l = r;
				inf->cmd_buf = b;
			}
		}
	}
	return (r);
}

/**
 * get_input - tay p tyap tyap type c d ie
 * @inf: var
 * Return: bytes
 */
ssize_t get_input(info_t *inf)
{
	static char *buf;
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(inf->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(inf, &buf, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buf + i;

		check_chain(inf, buf, &j, i, len);
		while (j < len)
		{
			if (is_chain(inf, buf, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			inf->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buf;
	return (r);
}

/**
 * read_buf - rrororororoor fufufufuf
 * @inf: var
 * @b: var
 * @j: var
 * Return: r
 */
ssize_t read_buf(info_t *inf, char *b, size_t *j)
{
	ssize_t r = 0;

	if (*j)
		return (0);
	r = read(inf->readfd, b, READ_BUF_SIZE);
	if (r >= 0)
		*j = r;
	return (r);
}

/**
 * _getline - vargar
 * @inf: gren
 * @w: varLL
 * @z: varLL
 * Return: s
 */
int _getline(info_t *inf, char **w, size_t *z)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *w;
	if (p && z)
		s = *z;
	if (i == len)
		i = len = 0;

	r = read_buf(inf, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (z)
		*z = s;
	*w = p;
	return (s);
}

/**
 * sigintHandler - salamanka comasatas
 * @u: var ooooonly youuuuuuu...bam...bam
 * Return: void
 */
void sigintHandler(__attribute__((unused))int u)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
