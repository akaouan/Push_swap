/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:04:04 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/07 18:04:06 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_ra(char *s1, char *s2, t_list **stack_a)
{
	int	i;

	i = 0;
	if (ft_strlen(s2) != ft_strlen(s1))
		return (0);
	while (s2[i] != '\n')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	r(stack_a);
	return (1);
}

int	check_rb(char *s1, char *s2, t_list **stack_b)
{
	int	i;

	i = 0;
	if (ft_strlen(s2) != ft_strlen(s1))
		return (0);
	while (s2[i] != '\n')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	r(stack_b);
	return (1);
}

int	check_rr(char *s1, char *s2, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	if (ft_strlen(s2) != ft_strlen(s1))
		return (0);
	while (s2[i] != '\n')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	r(stack_a);
	r(stack_b);
	return (1);
}

int	check_rra(char *s1, char *s2, t_list **stack_a)
{
	int	i;

	i = 0;
	if (ft_strlen(s2) != ft_strlen(s1))
		return (0);
	while (s2[i] != '\n')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	rr(stack_a);
	return (1);
}

int	check_rrb(char *s1, char *s2, t_list **stack_b)
{
	int	i;

	i = 0;
	if (ft_strlen(s2) != ft_strlen(s1))
		return (0);
	while (s2[i] != '\n')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	rr(stack_b);
	return (1);
}
