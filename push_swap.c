/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:36:45 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/06 21:39:15 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/push_swap.h"

void	sorting(t_elemnts *elems)
{
	if (elems->stack_size == 2)
	{
		if (elems->stack_a->index > elems->stack_a->next->index)
			swap(&elems->stack_a, 'a');
	}
	else if (elems->stack_size == 3)
		sort_tr(&elems->stack_a);
	else if (elems->stack_size == 4)
		sort_five(&elems->stack_a, &elems->stack_b, 1);
	else if (elems->stack_size == 5)
		sort_five(&elems->stack_a, &elems->stack_b, 2);
	else if (elems->stack_size == 6)
		sort_five(&elems->stack_a, &elems->stack_b, 3);
	else
		sort_stack(&elems->stack_a, &elems->stack_b);
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
	sort_tab(elems->tab, elems->size);
	put_index(elems->stack_a, elems->tab);
	elems->stack_size = ft_lstsize(elems->stack_a);
}

int	is_valid(int ac, char **av)
{
	if (!check_argements(av) || !check_duplicate(ac, av))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_elemnts	elems;

	if (ac > 2)
	{
		if (!is_valid(ac, av))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		else if (is_sorted(ac, av))
			return (0);
		init_elements(&elems, ac - 1);
		fill_stacks(&elems, av);
		sorting(&elems);
		free(elems.tab);
	}
}
