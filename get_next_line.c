/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:17:26 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/05 21:25:23 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_new_exicted(char *last)
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
	char txt[BUFFER_SIZE + 1];
	char *line;
	int read_nb;

	read_nb = 1;
	while (read_nb && !check_new_exicted(last))
	{
		read_nb = read(fd, txt, BUFFER_SIZE);
		if (read_nb == -1)
			return (0);
		txt[read_nb] = '\0';
		last = join_strings(last, txt);
	}
	if (read_nb == 0)
	{
		if (!last[0])
			return(0);
		line = last;
		last = 0;
		return (line);
	}
	line = get_before_new(last);
	last = get_after_new(last);
	return (line);
}