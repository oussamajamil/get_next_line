/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:30:38 by ojamil            #+#    #+#             */
/*   Updated: 2021/11/16 15:18:59 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*change_result(char *result)
{
	int		i;
	int		j;
	char	*new_result;

	i = 0;
	j = 0;
	while (result[i] != '\0' && result[i] != '\n')
		i++;
	if (result[i] == '\n')
		i++;
	if (result[i] == 0)
	{
		free(result);
		return (NULL);
	}
	new_result = (char *)malloc(sizeof(char) * (ft_strlen(result) - i + 1));
	if (!new_result)
		return (NULL);
	while (result[i] != '\0')
		new_result[j++] = result[i++];
	new_result[j] = 0;
	free(result);
	return (new_result);
}

char	*ft_get_line(char *str)
{
	int		len;
	char	*line;
	int		j;

	len = 0;
	j = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (j < len)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = 0;
	return (line);
}

char	*ft_get(char *str, int fd)
{
	char	*buffer;
	int		a;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	a = 1;
	while (1)
	{
		a = read(fd, buffer, BUFFER_SIZE);
		if (a == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[a] = 0;
		str = ft_strjoin(str, buffer);
		if (ft_strchr(str, '\n') != NULL || a == 0)
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*result[65536];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result[fd] = ft_get(result[fd], fd);
	if (result[fd] == NULL)
		return (NULL);
	line = ft_get_line(result[fd]);
	result[fd] = change_result(result[fd]);
	return (line);
}
