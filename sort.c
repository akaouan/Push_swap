/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:56:11 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/06 16:58:41 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/push_swap.h"

void	sort_five(t_list **stack_a, t_list **stack_b, int size)
{
	push_min(stack_a, stack_b, size);
	sort_tr(stack_a);
	while (size--)
		push_a(stack_a, stack_b);
}

void	rb_pusha(t_list **stack_a, t_list **stack_b)
{
	while (1)
	{
		if (!is_elem1(*stack_b, (*stack_a)->index - 1))
			break ;
		if ((*stack_b)->index == ((*stack_a)->index - 1))
		{
			push_a(stack_a, stack_b);
			break ;
		}
		else
			r(stack_b, 'b');
	}
}

void	rrb_pusha(t_list **stack_a, t_list **stack_b)
{
	while (1)
	{
		if (!is_elem1(*stack_b, (*stack_a)->index - 1))
			break ;
		if ((*stack_b)->index == (*stack_a)->index - 1)
		{
			push_a(stack_a, stack_b);
			break ;
		}
		else
			rr(stack_b, 'b');
	}
}

void	push_back(t_list **stack_a, t_list **stack_b, int up_down)
{
	if (up_down)
		rb_pusha(stack_a, stack_b);
	else if (!up_down)
		rrb_pusha(stack_a, stack_b);
	if (*stack_b && (*stack_b)->index > ft_lstlast(*stack_a)->index
		&& (*stack_b)->index < (*stack_a)->index - 1)
	{
		push_a(stack_a, stack_b);
		r(stack_a, 'a');
	}
	if (*stack_b && !is_elem1(*stack_b, (*stack_a)->index - 1))
		rr(stack_a, 'a');
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	t_range	*range;
	int		save_index;

	range = malloc(sizeof(t_range));
	init_range(*stack_a, range);
	while (ft_lstsize(*stack_a) > 5)
	{
		push_elms(stack_a, stack_b, range, up_or_down(*stack_a, range));
		new_range(*stack_a, range);
	}
	sort_five(stack_a, stack_b, 2);
	save_index = ft_lstlast(*stack_a)->index;
	ft_lstlast(*stack_a)->index = -1;
	while (*stack_b)
		push_back(stack_a, stack_b, up_down(*stack_b, (*stack_a)->index - 1));
	while (ft_lstlast(*stack_a)->index != -1)
		rr(stack_a, 'a');
	ft_lstlast(*stack_a)->index = save_index;
	free(range);
}
