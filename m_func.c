#include "shell.h"

/**
 * interactive - rwhaat i'veeee doooone
 * @inf: svar
 * Return: if interactive 1 , else 0
 */
int interactive(info_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
 * is_delim - what i'v doneee
 * @k: var
 * @d: var
 * Return: if true 1, if false 0
 */
int is_delim(char k, char *d)
{
	while (*d)
		if (*d++ == k)
			return (1);
	return (0);
}

/**
 *_isalpha - dooooone to tasat myself
 *@k: var
 *Return: if c is alphabetic 1, else 0
 */

int _isalpha(int k)
{
	if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - cswaaaay yayayay ohayayyaya
 *@g: var
 *Return:  if no numbers in string 0, else converto spertoro
 */

int _atoi(char *g)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  g[i] != '\0' && flag != 2; i++)
	{
		if (g[i] == '-')
			sign *= -1;

		if (g[i] >= '0' && g[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (g[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
