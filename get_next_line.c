/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:17:26 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/03 16:24:14 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t get_str_len(char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char *loop_and_get_n(char *last)
{
	size_t i;
	size_t j;
	char *line;
	char *next_str;
	size_t len;

	len = 0;
	next_str = get_n_index(last, &len);
	line = malloc(sizeof(char) * (len + 1));
	i = 0;
	j = 0;
	while (last[i])
	{
		line[i] = last[i];
		if (last[i] == '\n')
			break;
		i++;
	}
	line[++i] = '\0';
	last = get_n_index(last, &len);
	return (line);
}

size_t check_last(char *last)
{
	size_t i;

	i = 0;
	if (!last)
		return (1);
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
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char *get_next_line(size_t fd)
{
	static char *last;
	// printf("start function\n%s\n", last);
	char txt[BUFFER_SIZE + 1];
	char *line;
	size_t j;

	j = 0;
	while (1)
	{
		if (check_last(last))
		{
			if (!read(fd, txt, BUFFER_SIZE))
				return (0);
			// printf("before join \t %s\n", last);
			last = join_strings(last, txt);
			// printf("after join \t %s\n", last);
		}
		else
		{
			// last = get_n_index(last, &j);
			line = loop_and_get_n(last);
			last = get_n_index(last, &j);
			return (line);
		}
	}
	return (0);
}
