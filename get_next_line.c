/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:07:10 by ojamil            #+#    #+#             */
/*   Updated: 2021/11/15 16:29:55 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *ft_change_result(char *result)
{
	int i;
	char *new_resul;
	int j;

	i = 0;
	j = 0;
	while (result[i] != '\n' && result[i] != '\0')
		i++;
	if (result[i] == '\0')
	{
		free(result);
		return (NULL);
	}
	new_resul = malloc(sizeof(char) * (ft_strlen(result) - i + 1));
	if (!new_resul)
		return (NULL);
	while (result[++i] != '\0')
	{
		new_resul[j] = result[i];
		j++;
	}
	new_resul[j] = 0;
	free(result);
	return (new_resul);
}

char *ft_read(char *result, int fd)
{
	char *buffer;
	int a;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	a = 1;
	while (a > 0 && ft_strchr(result, '\n') == NULL)
	{
		a = read(fd, buffer, BUFFER_SIZE);
		if (a == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[a] = 0;
		result = ft_strjoin(result, buffer);
	}
	free(buffer);
	return (result);
}
char *get_line(char *str)
{
	char *res;
	int len;
	int i;

	i = 0;
	len = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	if (str[len] == '\n')
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char *get_next_line(int fd)
{
	static char *result;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	result = ft_read(result, fd);
	if (result == NULL)
		return NULL;
	line = get_line(result);
	result = ft_change_result(result);
	return (line);
}