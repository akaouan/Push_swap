/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:03:26 by akaouan           #+#    #+#             */
/*   Updated: 2021/11/26 15:07:30 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 5
# include<stdlib.h>
# include<unistd.h>
# include<stdio.h>

int		to_check(char *s);
int		ft_strlen(char *str);
char	*join(char *s1, char *s2);
char	*after_nline(char *s, int start);
char	*before_nline(char *str, int end);
char	*get_next_line(int fd);
char	*alloc_back(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
#endif
