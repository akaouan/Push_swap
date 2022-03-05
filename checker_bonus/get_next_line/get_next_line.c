/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:14:29 by akaouan           #+#    #+#             */
/*   Updated: 2021/11/26 15:05:22 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

int	to_check(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*read_buffer(char *saved, int fd)
{
	char	*buff;
	int		max;

	buff = malloc(BUFFER_SIZE + 1);
	max = 1;
	while (to_check(saved) == -1 && max != 0)
	{
		max = read(fd, buff, BUFFER_SIZE);
		if (max == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[max] = '\0';
		saved = join(saved, buff);
	}
	free(buff);
	if (max == 0 && ft_strlen(saved) == 0)
	{
		free(saved);
		saved = NULL;
	}
	return (saved);
}

char	*get_next_line(int fd)
{
	static char	*saved = NULL;
	char		*line;
	int			index_line;

	if (to_check(saved) == -1)
		saved = read_buffer(saved, fd);
	if (!saved)
		return (NULL);
	index_line = to_check(saved);
	if (index_line == -1)
	{
		line = saved;
		saved = NULL;
		return (line);
	}
	line = ft_substr(saved, 0, index_line + 1);
	saved = after_nline(saved, index_line + 1);
	return (line);
}
