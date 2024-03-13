/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:29:10 by bekhodad          #+#    #+#             */
/*   Updated: 2023/11/04 16:13:04 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	free_func(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!a && !b)
		exit (1);
	if (a)
	{
		while ((*a) != NULL)
		{
			temp = *a;
			*a = (*a)->next;
			free(temp);
		}
	}
	if (b)
	{
		while ((*b) != NULL)
		{
			temp = *b;
			*b = (*b)->next;
			free(temp);
		}
	}
}

int	check_digits(char **av, int ac)
{
	int		i;
	int		j;
	int		num;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j] != '\0')
		{
			if (ft_isdigit(av[i][j]) == 0)
				return (1);
			j++;
		}
		num = ft_atoi(av[i]);
		i++;
	}
	return (0);
}

int	check_if_stack_is_sorted(t_stack **a)
{
	t_stack	*temp;

	temp = (*a);
	while (temp->next != NULL)
	{
		if (temp->index + 1 == temp->next->index)
			temp = temp->next;
		else
			return (1);
	}
	return (0);
}

int	check_greater(char **av, int ac)
{
	int			i;
	long int	result;

	i = 0;
	while (i < ac)
	{
		result = atoi_plus(av[i]);
		if (result > 2147483647 || result < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

long int	atoi_plus(char *nb)
{
	int			sign;
	long int	result;

	sign = 1;
	result = 0;
	while (*nb == '\t' || *nb == '\n' || *nb == '\v' || *nb == '\f'
		|| *nb == '\r' || *nb == ' ')
		nb++;
	if (*nb == '-')
	{
		sign = -1;
		nb++;
	}
	else if (*nb == '+')
		nb++;
	while (*nb >= '0' && *nb <= '9')
	{
		result = result * 10 + (*nb - '0');
		nb++;
	}
	return (result * sign);
}
