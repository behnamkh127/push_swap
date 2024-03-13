/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:26:56 by bekhodad          #+#    #+#             */
/*   Updated: 2023/11/01 16:49:57 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	cost_b(t_stack **b)
{
	int		size;
	t_stack	*temp;

	temp = *b;
	size = ps_lstsize(temp);
	while (temp)
	{
		if (temp->position < ((size / 2) + 1))
			temp->cost_b = temp->position;
		else
			temp->cost_b = temp->position - size;
		temp = temp->next;
	}
}

void	cost_a(t_stack **b, t_stack **a)
{
	int		size;
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *a;
	temp_b = *b;
	size = ps_lstsize(temp_a);
	while (temp_b)
	{
		if (temp_b->tar_pos < ((size / 2) + 1))
			temp_b->cost_a = temp_b->tar_pos;
		else
			temp_b->cost_a = temp_b->tar_pos - size;
		temp_b = temp_b->next;
	}
}

int	total_cost(t_stack **b, t_stack **a)
{
	int		min;
	t_stack	*temp;

	if (!b)
		return (-1);
	cost_b(b);
	cost_a(b, a);
	temp = *b;
	while (temp)
	{
		temp->total_cost = make_pos(temp->cost_a) + make_pos(temp->cost_b);
		temp = temp->next;
	}
	temp = *b;
	min = 2147483647;
	while (temp)
	{
		if (temp->total_cost < min)
			min = temp->total_cost;
		temp = temp->next;
	}
	return (min);
}

int	make_pos(int i)
{
	if (i >= 0)
		return (i);
	return (-i);
}
