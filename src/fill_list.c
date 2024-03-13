/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:59:29 by bekhodad          #+#    #+#             */
/*   Updated: 2023/11/02 10:25:51 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	add_new(t_stack *a, char *av)
{
	t_stack	*new;

	new = ps_lstnew(ft_atoi(av));
	ps_lstadd_back(&a, new);
}

void	ps_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*ptr;

	if (lst)
	{
		if (*lst)
		{
			ptr = ps_lstlast(*lst);
			ptr->next = new;
		}
		else
			*lst = new;
	}
}

t_stack	*ps_lstnew(int content)
{
	t_stack	*ptr;

	ptr = (t_stack *) malloc(sizeof(t_stack));
	if (ptr == 0)
		return (0);
	ptr->value = content;
	ptr->next = 0;
	return (ptr);
}

t_stack	*ps_lstlast(t_stack *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

int	ps_lstsize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
