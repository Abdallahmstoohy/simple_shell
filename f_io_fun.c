#include "shell.h"

/**
 * get_history_file - ghomo geniuse ile
 * @inf: var
 *
 * Return: allocateo stringo bingo
 */

char *get_history_file(info_t *inf)
{
	char *buf, *dir;

	dir = _getenv(inf, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * write_history - choly moly coly forlly
 * @inf: tvar
 *
 * Return: on success 1 , holy -1
 */
int write_history(info_t *inf)
{
	ssize_t f;
	char *filename = get_history_file(inf);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	f = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (f == -1)
		return (-1);
	for (node = inf->history; node; node = node->next)
	{
		_putsfd(node->str, f);
		_putfd('\n', f);
	}
	_putfd(BUF_FLUSH, f);
	close(f);
	return (1);
}

/**
 * read_history - reade writne liseten mommy
 * @inf: vart
 *
 * Return: histcount on success, 0 else where on this earth
 */
int read_history(info_t *inf)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(inf);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(inf, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_history_list(inf, buf + last, linecount++);
	free(buf);
	inf->histcount = linecount;
	while (inf->histcount-- >= HIST_MAX)
		delete_node_at_index(&(inf->history), 0);
	renumber_history(inf);
	return (inf->histcount);
}

/**
 * build_history_list - ancient egyptian are thisory mfs
 * @inf: var
 * @b: var
 * @lc: var
 *
 * Return: Always 0
 */
int build_history_list(info_t *inf, char *b, int lc)
{
	list_t *node = NULL;

	if (inf->history)
		node = inf->history;
	add_node_end(&node, b, lc);

	if (!inf->history)
		inf->history = node;
	return (0);
}

/**
 * renumber_history - rapalagrisim coco daydar
 * @inf: var
 * Return: the  histcount
 */
int renumber_history(info_t *inf)
{
	list_t *node = inf->history;
	int g = 0;

	while (node)
	{
		node->num = g++;
		node = node->next;
	}
	return (inf->histcount = g);
}
