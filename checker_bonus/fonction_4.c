/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:04:11 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/07 18:04:14 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_rotate(char *tab, t_elemnts *elem)
{
	if (check_ra(tab, "ra\n", &elem->stack_a))
		return (1);
	else if (check_rb(tab, "rb\n", &elem->stack_b))
		return (1);
	else if (check_rr(tab, "rr\n", &elem->stack_a, &elem->stack_b))
		return (1);
	else if (check_rra(tab, "rra\n", &elem->stack_a))
		return (1);
	else if (check_rrb(tab, "rrb\n", &elem->stack_b))
		return (1);
	else if (check_rrr(tab, "rrr\n", &elem->stack_a, &elem->stack_b))
		return (1);
	else
		return (0);
}

void	init_elements(t_elemnts *vars, int size)
{
	vars->tab = malloc(sizeof(int) * size);
	if (!vars->tab)
		return ;
	vars->stack_b = NULL;
	vars->stack_a = NULL;
	vars->size = size;
	vars->i = 1;
	vars->j = 0;
}

void	fill_stacks(t_elemnts *elems, char **av)
{
	while (elems->i < elems->size + 1)
	{
		elems->tab[elems->j++] = ft_atoi(av[elems->i]);
		ft_lstadd_back(&elems->stack_a, ft_lstnew(elems->tab[elems->j - 1]));
		elems->i++;
	}
	elems->stack_size = ft_lstsize(elems->stack_a);
}

int	is_valid(int ac, char **av)
{
	if (!check_argements(av) || !check_duplicate(ac, av))
		return (0);
	return (1);
}
