/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:29:13 by ojamil            #+#    #+#             */
/*   Updated: 2021/11/16 15:05:24 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*change_result(char *result);
char	*ft_get_line(char *str);
char	*ft_get(char *str, int fd);
char	*get_next_line(int fd);
size_t	ft_strlen(char *result);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
#endif
