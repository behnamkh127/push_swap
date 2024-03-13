/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:38:42 by bekhodad          #+#    #+#             */
/*   Updated: 2023/10/31 12:59:38 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	find_position(t_stack **s)
{
	int		i;
	t_stack	*temp;
	int		size;

	temp = *s;
	size = ps_lstsize(temp);
	i = 0;
	while (i < size)
	{
		temp->position = i;
		temp = temp->next;
		i++;
	}
}

void	tar_pos_find(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_b = *b;
	while (temp_b)
	{
		temp_a = *a;
		while (temp_a)
		{
			if (is_suprior_index(a, &temp_b))
			{
				temp_b->tar_pos = find_min_index(a);
				break ;
			}
			if (temp_b->index < temp_a->index)
				temp_a = exact_tar_pos(temp_a, temp_b);
			else
				temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
	}
}

int	is_suprior_index(t_stack **a, t_stack **b)
{
	int		max;
	t_stack	*temp;

	max = (*b)->index;
	temp = *a;
	while (temp)
	{
		if (max < (temp)->index)
			max = (temp)->index;
		(temp) = (temp)->next;
	}
	if (max == (*b)->index)
		return (1);
	return (0);
}

int	find_min_index(t_stack **a)
{
	int		min;
	t_stack	*temp;

	min = (*a)->index;
	temp = (*a)->next;
	while (temp)
	{
		if (temp->index < min)
			min = temp->index;
		temp = temp->next;
	}
	temp = (*a);
	while (temp->index != min)
		temp = temp->next;
	return (temp->position);
}

t_stack	*exact_tar_pos(t_stack *a, t_stack *b)
{
	int		nearest_index;

	nearest_index = a->index;
	b->tar_pos = a->position;
	a = a->next;
	while (a)
	{
		if (b->index < a->index
			&& a->index < nearest_index)
		{
			nearest_index = a->index;
			b->tar_pos = a->position;
		}
		a = a->next;
	}
	return (a);
}
