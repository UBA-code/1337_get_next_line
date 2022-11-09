/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:17:26 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/09 13:58:36 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t get_str_len(char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int check_new_exicted(char *last)
{
	size_t i;

	i = 0;
	if (!last || !last[0])
		return (0);
	while (last[i])
	{
		if (last[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	static char *last;
	char txt[BUFFER_SIZE + 1];
	char *line;
	int read_nb;

	line = NULL;
	read_nb = 1;
	while (read_nb && !check_new_exicted(last))
	{
		read_nb = read(fd, txt, BUFFER_SIZE);
		if (read_nb == -1)
		{
			free(last);
			return (0);
		}
		txt[read_nb] = '\0';
		if (read_nb == 0 && last)
			return (check_read_return(&last, line));
		if (read_nb == 0 && !last)
			return (0);
		last = ft_strjoin(last, txt);
	}
	if (read_nb == 0)
		return (check_read_return(&last, line));
	line = get_before_new(last);
	last = get_after_new(last);
	return (line);
}

/*
char *free_func(char *s1)
{
	free(s1);
	return (0);
}
*/

char *return_empty(void)
{
	char *new;

	new = malloc(sizeof(char) * 1);
	if (!new)
		return (0);
	new[0] = '\0';
	return (new);
}

char *check_read_return(char **last, char *line)
{
	if (!*last || !*(*last))
		return (0);
	line = *last;
	*last = 0;
	free(*last);
	return (line);
}
