/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:52:11 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 18:21:39 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rot_a_condition(t_ps *stack_a, int c_i, int temp, int *rotations)
{
	if (c_i < stack_a->size / 2)
	{
		while (stack_a->array[0] != temp)
		{
			rotate(stack_a);
			rotations[0] += 1;
		}
	}
	else
	{
		while (stack_a->array[0] != temp)
		{
			reverse_rotate(stack_a);
			rotations[2] += 1;
		}
	}
}

void	rot_b_condition(t_ps *stack_b, int i, int *rotations)
{
	if (i < stack_b->size / 2)
	{
		while (i + 1 > 0)
		{
			rotate(stack_b);
			rotations[1] += 1;
			i--;
		}
	}
	else
	{
		while (stack_b->size - i - 1 > 0)
		{
			reverse_rotate(stack_b);
			rotations[3] += 1;
			i++;
		}
	}
}

void	set_rotation_min_max(t_ps *stack_b, int min, int max, int *rotations)
{
	int	i;

	i = 0;
	if ((stack_b->array[stack_b->size - 1] == min
			&& stack_b->array[i] == max)
		|| (stack_b->array[stack_b->size - 1] == max
			&& stack_b->array[i] == min))
		return ;
	while (stack_b->array[i] != min && stack_b->array[i] != max)
		i++;
	rot_b_condition(stack_b, i, rotations);
}

void	rotate_back(t_ps *stack_b)
{
	int	max;
	int	index;

	max = find_max_number(stack_b);
	index = find_max_num_index(stack_b, max);
	if (index < stack_b->size / 2)
	{
		while (index > 0)
		{
			rotate(stack_b);
			write(1, "rb\n", 3);
			index--;
		}
	}
	else
	{
		while (stack_b->size - index > 0)
		{
			reverse_rotate(stack_b);
			write(1, "rrb\n", 4);
			index++;
		}
	}
}

int	set_rotation(t_ps *stack_a, t_ps *stack_b, int min, int max)
{
	int	i;

	i = 0;
	while (i < stack_b->size)
	{
		if ((stack_b->array[i] == min && stack_b->array[i + 1] == max)
			|| (stack_b->array[i] == max && stack_b->array[i + 1] == min))
			i++;
		if ((stack_b->array[i] > stack_a->array[0]
				&& stack_b->array[i + 1] < stack_a->array[0])
			|| (stack_b->array[i] < stack_a->array[0]
				&& stack_b->array[i + 1] > stack_a->array[0]))
			return (i);
		i++;
	}
	return (i);
}
