#include "shell.h"

/**
 * _erratoi - fire works exploding in my hands
 * @f: tcar
 * Return: if no numbers in string 0 , convert number else
 *       -1 on error
 */
int _erratoi(char *f)
{
	int i = 0;
	unsigned long int result = 0;

	if (*f == '+')
		f++;
	for (i = 0;  f[i] != '\0'; i++)
	{
		if (f[i] >= '0' && f[i] <= '9')
		{
			result *= 10;
			result += (f[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - tsayyyy okh yeyeye ehyeyeyeyea yaaa
 * @inf: var
 * @es: var
 * Return: if no numbers in string 0, converte the number else
 *        -1 on error
 */
void print_error(info_t *inf, char *es)
{
	_eputs(inf->fname);
	_eputs(": ");
	print_d(inf->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(inf->argv[0]);
	_eputs(": ");
	_eputs(es);
}

/**
 * print_d - fyou look so happy when i'm not with you
 * @m: tvar
 * @f: var
 * Return: number of characters printed
 */
int print_d(int m, int f)
{
	int (*__putchar)(char) = _putchar;
	int i, c = 0;
	unsigned int _abs_, current;

	if (f == STDERR_FILENO)
		__putchar = _eputchar;
	if (m < 0)
	{
		_abs_ = -m;
		__putchar('-');
		c++;
	}
	else
		_abs_ = m;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			c++;
		}
		current %= i;
	}
	__putchar('0' + current);
	c++;

	return (c);
}

/**
 * convert_number - save you tears for another day
 * @n: var
 * @b: var
 * @f: var
 * Return: string, can't you see ohh
 */
char *convert_number(long int n, int b, int f)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = n;

	if (!(f & CONVERT_UNSIGNED) && n < 0)
	{
		n = -n;
		sign = '-';

	}
	array = f & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % b];
		n /= b;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - blind idiot
 * @b: var
 * Return:  0;
 */
void remove_comments(char *b)
{
	int i;

	for (i = 0; b[i] != '\0'; i++)
		if (b[i] == '#' && (!i || b[i - 1] == ' '))
		{
			b[i] = '\0';
			break;
		}
}
