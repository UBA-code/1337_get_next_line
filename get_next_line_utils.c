/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:09:59 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/09 14:03:57 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_before_new(char *last)
{
	size_t i;

	i = 0;
	while (last[i])
	{
		if (last[i] == '\n')
		{
			if (get_str_len(&last[i + 1]) <= 1)
				return (return_empty());
			return (get_substring(last, i + 1));
		}
		i++;
	}
	return (last);
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
			if (get_str_len(&last[i + 1]) <= 1)
				return (return_empty);
			str = get_substring(&last[i + 1], get_str_len(&last[i + 1]));
			free(last);
			return (str);
		}
		i++;
	}
	return (last);
}

char *get_substring(char *str, size_t len)
{
	char *new_str;
	size_t i;

	i = 0;
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (0);
	while ( str[i] && i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*str_copy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
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
	if (!s1)
		s1 = get_substring("", 0);
	if (s1)
		str_copy(final_str, s1);
	i = get_str_len(final_str);
	if (s2)
		str_copy(final_str + i, s2);
	free(s1);
	return (final_str);
}
