#include "shell.h"

/**
 **_strncpy - in into the lighhhht awaaay
 *@d: var
 *@s: var
 *@b: var
 *Return: liiiiiife life
 */
char *_strncpy(char *d, char *s, int b)
{
	int i, j;
	char *s = d;

	i = 0;
	while (s[i] != '\0' && i < b - 1)
	{
		d[i] = s[i];
		i++;
	}
	if (i < b)
	{
		j = i;
		while (j < b)
		{
			d[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - and into the liiight lighhhht
 *@d: tvar
 *@s: var
 *@r: var
 *Return: tsosok[gha ]
 */
char *_strncat(char *d, char *s, int r)
{
	int i, j;
	char *s = d;

	i = 0;
	j = 0;
	while (d[i] != '\0')
		i++;
	while (s[j] != '\0' && j < r)
	{
		d[i] = s[j];
		i++;
		j++;
	}
	if (j < r)
		d[i] = '\0';
	return (s);
}

/**
 **_strchr - hahhhahh hhhhhh haaaahhhhhhahe
 *@f: car
 *@d: tvar
 *Return:f
 */
char *_strchr(char *f, char d)
{
	do {
		if (*f == d)
			return (f);
	} while (*f++ != '\0');

	return (NULL);
}
