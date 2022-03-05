/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:03:52 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/07 18:04:00 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_sa(char *s1, char *s2, t_list **stack_a)
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
	swap(stack_a);
	return (1);
}

int	check_sb(char *s1, char *s2, t_list **stack_b)
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
	swap(stack_b);
	return (1);
}

int	check_ss(char *s1, char *s2, t_list **stack_a, t_list **stack_b)
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
	swap(stack_a);
	swap(stack_b);
	return (1);
}

int	check_pb(char *s1, char *s2, t_list **stack_a, t_list **stack_b)
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
	push_b(stack_a, stack_b);
	return (1);
}

int	check_pa(char *s1, char *s2, t_list **stack_a, t_list **stack_b)
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
	push_a(stack_a, stack_b);
	return (1);
}
