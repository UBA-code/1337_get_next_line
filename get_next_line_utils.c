/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:09:59 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/03 13:55:07 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char *get_last_str(char *txt, size_t *current, size_t *last)
{

	return (string);
}
*/



char *get_n_index(char 	*txt, size_t *len)
{
	size_t i;

	i = 0;
	while (txt[i])
	{
		if (txt[i] == '\n')
		{
			txt = &txt[++i];
			break;
		}
		++*len;
		i++;
	}
	return (txt);
}