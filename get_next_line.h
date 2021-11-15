/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:04:34 by ojamil            #+#    #+#             */
/*   Updated: 2021/11/15 16:10:30 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char *ft_strjoin(char *s1, char *s2);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strdup(const char *s1);
char *ft_change_result(char *result);
char *ft_read(char *result, int fd);
char *get_line(char *str);
char *get_next_line(int fd);
#endif