#include "shell.h"

/**
 **_memset - whatever you want, your fkn special, creep
 *@v: thvar
 *@l: tvar
 *@q: var
 *Return: (v) a pointer to the memory area v
 */
char *_memset(char *v, char l, unsigned int q)
{
	unsigned int i;

	for (i = 0; i < q; i++)
		v[i] = l;
	return (v);
}

/**
 * ffree - i was confiuced
 * @r: var
 */
void ffree(char **r)
{
	char **w = r;

	if (!r)
		return;
	while (*r)
		free(*r++);
	free(w);
}

/**
 * _realloc - some where i belong
 * @x: var
 * @o: var
 * @n: var
 * Return: pointer t nameen.
 */
void *_realloc(void *x, unsigned int o, unsigned int n)
{
	char *p;

	if (!x)
		return (malloc(n));
	if (!n)
		return (free(x), NULL);
	if (n == o)
		return (x);

	p = malloc(n);
	if (!p)
		return (NULL);

	o = o < n ? o : n;
	while (o--)
		p[o] = ((char *)x)[o];
	free(x);
	return (p);
}
