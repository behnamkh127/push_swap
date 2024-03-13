/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:14:16 by bekhodad          #+#    #+#             */
/*   Updated: 2023/11/03 13:37:02 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

int	find_index(t_stack *a)
{
	int		size;
	int		*array;
	t_stack	*new;
	int		i;

	size = ps_lstsize(a);
	array = (int *)malloc(sizeof(int) * size);
	new = a;
	i = 0;
	while (new)
	{
		array[i++] = new->value;
		new = new->next;
	}
	sort_array(array, size);
	fill_index(a, array, size);
	i = if_there_is_equal(array, size);
	free (array);
	if (i == 0)
		return (0);
	return (1);
}

void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	fill_index(t_stack *a, int *array, int size)
{
	t_stack	*temp;
	int		i;

	temp = a;
	while (temp)
	{
		i = 0;
		while (i < size)
		{
			if (temp->value == array[i])
			{
				temp->index = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

int	if_there_is_equal(int *array, int size)
{
	int		i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] == array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
