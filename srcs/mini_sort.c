/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:33:27 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 18:21:07 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_if_sorted(t_ps *stack_a)
{
	int	i;

	i = 0;
	while (i < stack_a->size - 1)
	{
		if (stack_a->array[i + 1] <= stack_a->array[i])
			return (0);
		i++;
	}
	return (1);
}

static int	find_min_index(t_ps *list)
{
	int	min_index;
	int	i;

	min_index = 0;
	i = 1;
	while (i < list->size)
	{
		if (list->array[i] < list->array[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

static void	min_element_push_b(t_ps *stack_a, t_ps *stack_b)
{
	int	position;
	int	temp;

	while (stack_a->size > 3)
	{
		position = find_min_index(stack_a);
		temp = stack_a->array[position];
		if (position < stack_a->size / 2)
		{
			while (stack_a->array[0] != temp)
				rotate_a(stack_a);
		}
		else
		{
			while (stack_a->array[0] != temp)
				reverse_rotate_a(stack_a);
		}
		push_a_b(stack_a, stack_b);
	}
}

void	push_back(t_ps *stack_a, t_ps *stack_b)
{
	while (stack_b->size != 0)
		push_b_a(stack_b, stack_a);
}

void	mini_sort(t_ps *stack_a, t_ps *stack_b)
{
	if (check_if_sorted(stack_a))
		return ;
	if (stack_a->size == 1)
		return ;
	else if (stack_a->size == 2)
	{
		two_num_sort(stack_a, stack_a->array[0], stack_a->array[1]);
		return ;
	}
	else if (stack_a->size == 3)
	{
		three_num_sort(stack_a, stack_a->array[0],
			stack_a->array[1], stack_a->array[2]);
		return ;
	}
	else
	{
		min_element_push_b(stack_a, stack_b);
		three_num_sort(stack_a, stack_a->array[0],
			stack_a->array[1], stack_a->array[2]);
		push_back(stack_a, stack_b);
	}
}
