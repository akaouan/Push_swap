/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:45:08 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/06 16:49:21 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/push_swap.h"

int	is_num(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '-' && (av[i + 1] > '9' || av[i + 1] < '0'))
			return (0);
		else if (av[i] != '-' && (av[i] < '0' || av[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

int	gr_max(char *av)
{
	if (ft_atoi(av) > 2147483647 || ft_atoi(av) < -2147483648)
		return (0);
	return (1);
}

int	check_argements(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!is_num(av[i]) || !gr_max(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(int ac, char **av)
{
	int	i;
	int	j;
	int	dup;

	dup = 0;
	i = 1;
	while (i < ac)
	{
		j = 1;
		dup = 0;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				dup++;
				if (dup > 1)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (j < ac)
	{
		if (ft_atoi(av[i]) > ft_atoi(av[j]))
			return (0);
		j++;
		i++;
	}
	return (1);
}
