#include "shell.h"

/**
 * _strlen - i'll save myself
 * @g: var
 * Return: length of string
 */
int _strlen(char *g)
{
	int j = 0;

	if (!g)
		return (0);

	while (*g++)
		j++;
	return (j);
}

/**
 * _strcmp - and staring the truth of candle light mommy
 * @g1: varg
 * @g2: var
 *
 * Return: alot of stuff shut up and read the code
 */
int _strcmp(char *g1, char *g2)
{
	while (*g1 && *g2)
	{
		if (*g1 != *g2)
			return (*g1 - *g2);
		g1++;
		g2++;
	}
	if (*g1 == *g2)
		return (0);
	else
		return (*g1 < *g2 ? -1 : 1);
}

/**
 * starts_with - with noththtththththing, diieeed again
 * @holy: var
 * @y: var
 *
 * Return: address of next char of holy or NULL
 */
char *starts_with(const char *holy, const char *y)
{
	while (*y)
		if (*y++ != *holy++)
			return (NULL);
	return ((char *)holy);
}

/**
 * _strcat - i'm so tired of being here
 * @d: varer
 * @s: tvar
 *
 * Return: fi yo yo yo
 */
char *_strcat(char *d, char *s)
{
	char *r = d;

	while (*d)
		d++;
	while (*s)
		*d++ = *s++;
	*d = *s;
	return (r);
}
