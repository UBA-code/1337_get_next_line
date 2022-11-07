/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:17:26 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/07 12:07:43 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int check_new_exicted(char *last)
{
	size_t i;

	i = 0;
	if (!last)
		return (0);
	while (last[i])
	{
		if (last[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *get_next_line(size_t fd)
{
	static char *last;
	char *txt;
	char *line;
	int read_nb;

	txt = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!txt)
		return (0);
	line = NULL;
	read_nb = 1;
	while (read_nb && !check_new_exicted(last))
	{
		read_nb = read(fd, txt, BUFFER_SIZE);
		if (read_nb == -1)
			return (free_func(last, txt));
		txt[read_nb] = '\0';
		// last = join_strings(last, txt);
		if (read_nb == 0 && last)
			return (check_read_return(&last, line, txt));
		last = ft_strjoin(last, txt);
	}
	if (read_nb == 0)
		return (check_read_return(&last, line, txt));
	line = get_before_new(last);
	last = get_after_new(last, txt);
	return (line);
}

char *free_func(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (0);
}

char *check_read_return(char **last, char *line, char *txt)
{
	if (!*(*last))
		return (0);
	line = *last;
	*last = 0;
	free_func(*last, txt);
	return (line);
}