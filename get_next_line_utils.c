/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:02:15 by ojamil            #+#    #+#             */
/*   Updated: 2021/11/15 16:32:11 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
	size_t i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strchr(const char *s, int c)
{
	int i;
	char *str;

	if(s == NULL)
		return(NULL);
	i = 0;
	str = (char *)s;
	while (str[i] != (char)c && str[i])
		i++;
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *str;
	size_t l;
	size_t i;
	size_t j;

	i = 0;
	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	l = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	free(s1);
	return (str);
}

char *ft_strdup(const char *s1)
{
	int i;
	int l;
	char *str;

	i = 0;
	l = ft_strlen(s1);
	str = malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}