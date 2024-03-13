/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3nums.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:12:43 by bekhodad          #+#    #+#             */
/*   Updated: 2023/11/04 16:13:10 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	sort_3nums(t_stack **a)
{
	if (!*a || !(*a)->next)
	{
		return (ft_putendl_fd("Stack A only has 1 number!", 2), exit(1));
	}
	if (((*a)->next && (*a)->value > (*a)->next->value)
		&& (((*a)->next->next) && (*a)->value > (*a)->next->next->value))
	{
		ra(a);
		ft_printf("ra\n");
	}
	else if ((*a)->next && ((*a)->next->value > (*a)->value)
		&& ((*a)->next->next) && (*a)->next->value > (*a)->next->next->value)
	{
		rra(a);
		ft_printf("rra\n");
	}
	if ((*a)->value > (*a)->next->value)
	{
		sa(a);
		ft_printf("sa\n");
	}
}

void	init_links(t_stack **a, t_stack **b, char **av, int ac)
{
	int		i;

	i = 2;
	(*a) = (t_stack *) malloc(sizeof(t_stack) * ac);
	(*b) = (t_stack *) malloc(sizeof(t_stack));
	(*a) = NULL;
	(*b) = NULL;
	(*a) = ps_lstnew(ft_atoi(av[1]));
	while (i < ac)
		add_new((*a), av[i++]);
}
