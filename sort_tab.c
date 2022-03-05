/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:58:59 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/06 16:59:44 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/push_swap.h"

void	swap_index(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				swap_index(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
