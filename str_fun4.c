#include "shell.h"

/**
 * **strtow - my ears huting my heart
 * @f: tca
 * @t: var
 * Return: anana nanan nnaan
 */

char **strtow(char *f, char *t)
{
	int j, i, m, k, p = 0;
	char **s;

	if (f == NULL || f[0] == 0)
		return (NULL);
	if (!t)
		t = " ";
	for (i = 0; f[i] != '\0'; i++)
		if (!is_delim(f[i], t) && (is_delim(f[i + 1], t) || !f[i + 1]))
			p++;

	if (p == 0)
		return (NULL);
	s = malloc((1 + p) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < p; j++)
	{
		while (is_delim(f[i], t))
			i++;
		k = 0;
		while (!is_delim(f[i + k], t) && f[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = f[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - are you ready ???
 * @w: var
 * @d: varr
 * Return: what do i say if i'm not the other
 */
char **strtow2(char *w, char d)
{
	int k, m, i, j, r = 0;
	char **y;

	if (w == NULL || w[0] == 0)
		return (NULL);
	for (i = 0; w[i] != '\0'; i++)
		if ((w[i] != d && w[i + 1] == d) ||
		    (w[i] != d && !w[i + 1]) || w[i + 1] == d)
			r++;
	if (r == 0)
		return (NULL);
	y = malloc((1 + r) * sizeof(char *));
	if (!y)
		return (NULL);
	for (i = 0, j = 0; j < r; j++)
	{
		while (w[i] == d && w[i] != d)
			i++;
		k = 0;
		while (w[i + k] != d && w[i + k] && w[i + k] != d)
			k++;
		y[j] = malloc((k + 1) * sizeof(char));
		if (!y[j])
		{
			for (k = 0; k < j; k++)
				free(y[k]);
			free(y);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			y[j][m] = w[i++];
		y[j][m] = 0;
	}
	y[j] = NULL;
	return (y);
}
