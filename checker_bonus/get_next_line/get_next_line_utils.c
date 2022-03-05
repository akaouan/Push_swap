/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:19:49 by akaouan           #+#    #+#             */
/*   Updated: 2021/11/26 15:04:04 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*join(char *s1, char *s2)
{
	int		i;
	char	*p;
	int		len;
	int		j;

	if (s1 == NULL)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = malloc(sizeof(char) * len);
	i = 0;
	j = 0;
	if (!p)
		return (NULL);
	while (s1[j])
		p[i++] = s1[j++];
	j = 0;
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	free(s1);
	return (p);
}

char	*after_nline(char *s, int start)
{
	char	*p;

	p = ft_strdup(s + start);
	free(s);
	return (p);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*p;

	size = 0;
	i = 0;
	p = NULL;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	while (size < len && s[size])
		size++;
	p = malloc(sizeof(char) * size + 1);
	if (!p)
		return (NULL);
	while (i < size)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
