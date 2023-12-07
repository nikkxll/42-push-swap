/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:46:33 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/07 18:28:16 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_num_index(t_ps *stack_b, int max)
{
	int	i;

	i = 0;
	while (i < stack_b->size)
	{
		if (stack_b->array[i] == max)
			return (i);
		i++;
	}
	return (i);
}

int	find_min_number(t_ps *stack_b)
{
	int	min;
	int	i;

	min = 2147483647;
	i = 0;
	while (i < stack_b->size)
	{
		if (stack_b->array[i] < min)
			min = stack_b->array[i];
		i++;
	}
	return (min);
}

int	find_max_number(t_ps *stack_b)
{
	int	max;
	int	i;

	max = -2147483648;
	i = 0;
	while (i < stack_b->size)
	{
		if (stack_b->array[i] > max)
			max = stack_b->array[i];
		i++;
	}
	return (max);
}

int	find_top(t_ps *stack_a, t_ps *support, int range_max, int start)
{
	int	i;
	int	temp;

	i = 0;
	temp = start;
	while (i < stack_a->size)
	{
		start = temp;
		while (start < range_max)
		{
			if (stack_a->array[i] == support->array[start])
				return (i);
			start++;
		}
		i++;
	}
	return (i);
}

int	find_bottom(t_ps *stack_a, t_ps *support, int range_max, int start)
{
	int	i;
	int	j;
	int	temp;

	i = stack_a->size;
	j = 0;
	temp = start;
	while (i > 0)
	{
		start = temp;
		while (start < range_max)
		{
			if (stack_a->array[i] == support->array[start])
				return (i);
			start++;
		}
		i--;
	}
	return (i);
}
