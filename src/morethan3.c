/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morethan3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:49:44 by bekhodad          #+#    #+#             */
/*   Updated: 2023/11/01 11:15:32 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	sort_more(t_stack **a, t_stack **b, int ac)
{
	int		i;
	int		min_cost;
	int		size;

	i = 0;
	while (++i < ac - 3)
		pb(a, b);
	sort_3nums(a);
	size = ps_lstsize(*b);
	while (size > 0)
	{
		if (!b)
			break ;
		find_position(a);
		find_position(b);
		tar_pos_find(a, b);
		min_cost = total_cost(b, a);
		do_push(b, a, min_cost);
		size--;
	}
	final_sort(a);
}

void	do_push(t_stack **b, t_stack **a, int min)
{
	t_stack	*temp;

	temp = *b;
	while (min != temp->total_cost)
		temp = temp->next;
	while (min--)
	{
		if (temp->cost_a > 0 && temp->cost_b > 0)
			do_push1(a, b, temp);
		else if (temp->cost_a < 0 && temp->cost_b < 0)
			do_push2(a, b, temp);
		else if (temp->cost_a > 0)
			do_push3(a, temp);
		else if (temp->cost_b > 0)
			do_push4(b, temp);
		else if (temp->cost_b < 0)
			do_push5(b, temp);
		else if (temp->cost_a < 0)
			do_push6(a, temp);
	}
	pa(b, a);
	ft_printf("pa\n");
}

void	do_push1(t_stack **a, t_stack **b, t_stack *temp)
{
	rr(a, b);
	temp->cost_a -= 1;
	temp->cost_b -= 1;
	ft_printf("rr\n");
}

void	final_sort(t_stack **a)
{
	t_stack	*temp;
	int		i;
	int		size;

	size = ps_lstsize(*a);
	i = 0;
	temp = (*a);
	while (temp->index != 0)
	{
		i++;
		temp = temp->next;
	}
	if (i < (size / 2) + 1)
	{
		while (i--)
			do_push3(a, temp);
	}
	else
	{
		while (i++ != size)
			do_push6(a, temp);
	}
}
