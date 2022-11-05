/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:09:59 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/05 21:25:08 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_after_new(char *last)
{
	size_t i;

	i = 0;
	while (last[i])
	{
		if (last[i] == '\n')
			return (&last[i + 1]);
		i++;
	}
	return (last + i);
}

char	*get_before_new(char *last)
{
	size_t i;

	i = 0;
	while (last[i])
	{
		if (last[i] == '\n')
			return (get_substring(last, i + 1));
		i++;
	}
	return (0);
}


char *get_substring(char *str, size_t len)
{
	char *new_str;
	size_t i;

	i = 0;
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (0);
	while (str[i] && i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

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


char *join_strings(char *s1, char *s2)
{
	char *new_str;
	size_t i;
	size_t j;

	i = -1;
	j = 0;
	if (!s1)
		s1 = strdup("");
	new_str = malloc(sizeof(char) * (get_str_len(s1) +  get_str_len(s2) + 1));
	if (!new_str)
		return (0);
	if (s1)
	{
		while (s1[++i])
			new_str[i] = s1[i];
	}
	if (s2)
		while (s2[j])
			new_str[i++] = s2[j++];
	free(s1);
	new_str[i] = '\0';
	return (new_str);
}
