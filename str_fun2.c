#include "shell.h"

/**
 * _strcpy - my azz is huring meeee from sitting all the dayyyy
 * @d: var
 * @s: var
 * Return: whatever
 */
char *_strcpy(char *d, char *s)
{
	int i = 0;

	if (d == s || s == 0)
		return (d);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = 0;
	return (d);
}

/**
 * _strdup - all of your tears
 * @s: var
 * Return: hands through all of this years
 */
char *_strdup(const char *s)
{
	int l = 0;
	char *ret;

	if (s == NULL)
		return (NULL);
	while (*s++)
		l++;
	ret = malloc(sizeof(char) * (l + 1));
	if (!ret)
		return (NULL);
	for (l++; l--;)
		ret[l] = *--s;
	return (ret);
}

/**
 *_puts - alone all the timeeee
 *@s: var
 * Return: wipe away all of your tears
 */
void _puts(char *s)
{
	int i = 0;

	if (!s)
		return;
	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}

/**
 * _putchar - hand through all of this years
 * @f: var
 * Return: s 1.
 */
int _putchar(char f)
{
	static int i;
	static char j[WRITE_BUF_SIZE];

	if (f == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, j, i);
		i = 0;
	}
	if (f != BUF_FLUSH)
		j[i++] = f;
	return (1);
}
