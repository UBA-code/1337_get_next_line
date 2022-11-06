/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:09:59 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/06 21:50:05 by ybel-hac         ###   ########.fr       */
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

char *get_after_new(char *last)
{
	size_t i;
	char *str;

	i = 0;
	while (last[i])
	{
		if (last[i] == '\n')
		{
			str = get_substring(last + (i + 1), get_str_len(last + (i + 1)));
			free(last);
			return (str);
		}
		i++;
	}
	return (last);
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
/*
char *join_strings(char *s1, char *s2)
{
	char *new_str;
	size_t i;
	size_t j;

	i = -1;
	j = 0;
	new_str = malloc(sizeof(char) * (get_str_len(s1) +  get_str_len(s2) + 1));
	if (!new_str)
		return (0);
	if (s1)
	{
		while (s1[++i])
			new_str[i] = s1[i];
		free(s1);
	}
	if (s2)
	{
		while (s2[j])
			new_str[i++] = s2[j++];
	}
	new_str[i] = '\0';
	return (new_str);
}
*/


char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	free(src);
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*final_str;
	int		total_len;
	int		i;

	i = 0;
	total_len = get_str_len(s1) + get_str_len(s2);
	final_str = malloc(sizeof(char) * (total_len + 1));
	if (!final_str)
		return (0);
	if (s1)
	{
		ft_strcpy(final_str + i, s1);
	}
	i = get_str_len(final_str);
	ft_strcpy(final_str + i, s2);
	return (final_str);
}
