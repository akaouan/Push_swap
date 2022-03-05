/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:17:04 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/07 17:54:00 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "checker.h"

int	check_rrr(char *s1, char *s2, t_list **stack_a, t_list **stack_b)
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
	rr(stack_b);
	return (1);
}

void	check_actions(char *tab, t_elemnts *elem)
{
	if (tab[0] == '\n')
		return ;
	else if (check_sa(tab, "sa\n", &elem->stack_a))
		return ;
	else if (check_sb(tab, "sb\n", &elem->stack_b))
		return ;
	else if (elem->size > 1
		&& check_ss(tab, "ss\n", &elem->stack_a, &elem->stack_b))
		return ;
	else if (check_pb(tab, "pb\n", &elem->stack_a, &elem->stack_b))
		return ;
	else if (check_pa(tab, "pa\n", &elem->stack_a, &elem->stack_b))
		return ;
	if (elem->size > 1 && check_rotate(tab, elem))
		return ;
	else
	{
		write(1, "ERROR\n", 6);
		exit(0);
	}
	free(tab);
}

int	is_sorted1(t_list *stack)
{
	t_list	*second;

	if (!stack)
		return (0);
	second = stack->next;
	while (second)
	{
		if (stack->p > second->p)
			return (0);
		stack = stack->next;
		second = second->next;
	}
	return (1);
}

void	reading(t_elemnts *elems)
{
	elems->tb = get_next_line(0);
	if (!elems->tb)
		return ;
	while (elems->tb[0] != '\n')
	{
		check_actions(elems->tb, elems);
		elems->tb = get_next_line(0);
		if (elems->tb == NULL)
			return ;
	}
}

int	main(int ac, char **av)
{
	t_elemnts	elems;

	if (ac > 1)
	{
		if (!is_valid(ac, av))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		init_elements(&elems, ac - 1);
		fill_stacks(&elems, av);
		reading(&elems);
		if (is_sorted1(elems.stack_a) && !elems.stack_b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		free(elems.tab);
	}
}
