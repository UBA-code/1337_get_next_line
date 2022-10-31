/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:17:26 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/10/31 18:58:06 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t get_str_len(char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *loop_and_get_n(char *last)
{
	size_t i;
	size_t j;
	char *line;

	line = malloc(sizeof(char) *);
	i = 0;
	j = 0;
	while (last[i])
	{
		line[i] = last[i];
		if (last[i] == '\n')
			break;
		i++;
	}
	last[++i] = '\0';
	return ();
}

size_t check_last(char *last)
{
	size_t i;

	i = 0;
	while (last[i])
	{
		if (last[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char *join_strings(char *s1, char *s2)
{
	size_t i;
	size_t j;
	char *str;

	str = malloc(sizeof(char) * (get_str_len(s1) + get_str_len(s2)));
	if (!str)
	{
		free(str);
		return (0);
	}
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		s1[i++] = *s2[j++];
	*s1 = '\0';
	return (str);
}

char *get_next_line(size_t fd)
{
	static char *last;
	char txt[BUFFER_SIZE + 1];
	while (1)
	{
		if (check_last(last))
		{
			read(fd, txt, BUFFER_SIZE);
			last = join_strings(last, txt);
		}
		else
			return (loop_and_get_n(last));
	}

	return (0);
}
