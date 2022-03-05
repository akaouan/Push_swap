/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:31:26 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/06 16:32:50 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/push_swap.h"

int	indexu(int nm, int *tab)
{
	int	i;

	i = 0;
	while (1)
	{
		if (nm == tab[i])
			return (i);
		i++;
	}
}

void	put_index(t_list *stack, int *tab)
{
	while (stack)
	{
		stack->index = indexu(stack->p, tab);
		stack = stack->next;
	}
}

int	is_elem(t_list *stack, t_range *range)
{
	t_list	*head;

	head = stack;
	while (head != NULL)
	{
		if (head->index <= range->max && head->index >= range->min)
			return (1);
		head = head->next;
	}
	return (0);
}

void	init_range(t_list *stack_a, t_range *range)
{
	range->min = 0;
	range->max = ((ft_lstsize(stack_a) - 5) / 4) + 1;
	range->mid = (range->min + range->max) / 2;
}

void	new_range(t_list *stack_a, t_range *range)
{
	range->min = range->max;
	range->max += ((ft_lstsize(stack_a) - 5) / 4) + 1;
	range->mid = (range->min + range->max) / 2;
}
