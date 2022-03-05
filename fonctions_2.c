/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:33:17 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/06 16:38:42 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/push_swap.h"

int	up_or_down(t_list *stack, t_range *range)
{
	int		i;
	int		size;
	t_list	*head;

	head = stack;
	size = ft_lstsize(stack);
	i = 0;
	while (i < (size / 2))
	{
		if (head->index <= range->max && head->index >= range->min)
			return (1);
		i++;
		head = head->next;
	}
	return (0);
}

void	rot_up(t_list **stack_a, t_list **stack_b, t_range *range)
{
	while (1)
	{
		if ((*stack_a)->index <= range->max
			&& (*stack_a)->index >= range->min)
		{
			push_b(stack_a, stack_b);
			if ((*stack_b)->index < range->mid)
				r(stack_b, 'b');
			return ;
		}
		r(stack_a, 'a');
	}
}

void	rot_down(t_list **stack_a, t_list **stack_b, t_range *range)
{
	while (1)
	{
		if ((*stack_a)->index <= range->max
			&& (*stack_a)->index >= range->min)
		{
			push_b(stack_a, stack_b);
			if ((*stack_b)->index < range->mid)
				r(stack_b, 'b');
			return ;
		}
		rr(stack_a, 'a');
	}
}

void	roatate_push(t_list **sa, t_list **sb, t_range *rng, int sing)
{
	if (sing)
		rot_up(sa, sb, rng);
	else if (!sing)
		rot_down(sa, sb, rng);
}

void	push_elms(t_list **sa, t_list **sb, t_range *rng, int up_down)
{
	while (is_elem(*sa, rng))
		roatate_push(sa, sb, rng, up_down);
}
