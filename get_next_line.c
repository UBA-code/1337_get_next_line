/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:17:26 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/10/31 14:08:50 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_str_len(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	loop_and_get_n(char *txt)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		
	}
}

char *get_next_line(int fd)
{
	static char *temp;
	char *txt;
	int current;

	txt = malloc(sizeof(char) * BUFFER_SIZE + 1);
	read(fd, txt, BUFFER_SIZE);
	txt[len] = '\0'; 
	len = get_str_len(txt);
	while ()
	{
		
	}
	return (0);
}
