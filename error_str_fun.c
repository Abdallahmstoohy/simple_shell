#include "shell.h"

/**
 *_eputs - nergar zay zmamnaaaaan
 * @s: var
 *
 * Return: Nothing
 */
void _eputs(char *s)
{
	int j = 0;

	if (!s)
		return;
	while (s[j] != '\0')
	{
		_eputchar(s[j]);
		j++;
	}
}

/**
 * _eputchar - flfofloo loo loo
 * @d: car
 *
 * Return: sometimes 0 but i'm donkey
 */
int _eputchar(char d)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (d != BUF_FLUSH)
		buf[i++] = d;
	return (1);
}

/**
 * _putfd - who who who whow ho
 * @e: Tvar
 * @f: var
 *
 * Return: look 0, but don't see 1
 */
int _putfd(char e, int f)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (e == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(f, buf, i);
		i = 0;
	}
	if (e != BUF_FLUSH)
		buf[i++] = e;
	return (1);
}

/**
 *_putsfd - last last last
 * @s: var
 * @f: var
 *
 * Return: the number of chars put
 */
int _putsfd(char *s, int f)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s)
	{
		i += _putfd(*s++, f);
	}
	return (i);
}
