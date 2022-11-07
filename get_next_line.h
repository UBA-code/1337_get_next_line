/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:18:11 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/07 15:49:01 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include "stdio.h"
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *get_next_line(int fd);
char *get_after_new(char *last, char *txt);
char	*get_before_new(char *last);
char *get_substring(char *str, size_t len);
size_t get_str_len(char *str);
// char *join_strings(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char *check_read_return(char **last, char *line, char *txt);
char *free_func(char *s1, char *s2);

#endif