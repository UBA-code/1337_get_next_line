/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:09:59 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/03 16:18:30 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char *get_last_str(char *txt, size_t *current, size_t *last)
{

	return (string);
}
*/



char *get_n_index(char 	*last, size_t *len)
{
	size_t i;
	size_t last_len;
	
	last_len = get_str_len(last);
	i = 0;
	while (i < last_len)
	{
		if (last[i] == '\n')
			break;
		++*len;
		i++;
	}
	return (last + (++i));
}
