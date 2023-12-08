/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:29:36 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 18:21:35 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	find_place(t_ps *stack_a, t_ps *stack_b, int *rotations)
{
	int	min;
	int	max;
	int	position;

	min = find_min_number(stack_b);
	max = find_max_number(stack_b);
	position = 0;
	if (stack_a->array[0] < min || stack_a->array[0] > max)
		set_rotation_min_max(stack_b, min, max, rotations);
	else
	{
		position = set_rotation(stack_a, stack_b, min, max);
		rot_b_condition(stack_b, position, rotations);
	}
}

static void	push_right_place_b(t_ps *s_a, t_ps *s_b, int cheap, int *rotations)
{
	int	temp;

	temp = s_a->array[cheap];
	rot_a_condition(s_a, cheap, temp, rotations);
	if (s_b->size == 0 || s_b->size == 1)
	{
		rotation_steps(rotations);
		push_a_b(s_a, s_b);
	}
	else
	{
		if (s_b->size == 3)
			three_num_desc_sort_b(s_b, s_b->array[0],
				s_b->array[1], s_b->array[2]);
		find_place(s_a, s_b, rotations);
		rotation_steps(rotations);
		push_a_b(s_a, s_b);
	}
}

static int	find_cheapest(t_ps *s_a, t_ps *support, int range_max, int start)
{
	int	temp_up;
	int	temp_bottom;
	int	res;

	temp_up = find_top(s_a, support, range_max, start);
	res = temp_up;
	temp_bottom = find_bottom(s_a, support, range_max, start);
	if (s_a->size - temp_bottom + 1 < temp_up)
		res = temp_bottom;
	return (res);
}

static void	large_sort(t_ps *s_a, t_ps *s_b, t_ps *sup, int *rotations)
{
	int	counter;
	int	set;
	int	blk;
	int	cheap_index;

	counter = 0;
	set = 11;
	if (s_a->size <= 100)
		set = 6;
	blk = 0;
	cheap_index = 0;
	while (counter < sup->size)
	{
		if (counter > s_a->size / 2 && s_a->size <= 100 && sup->size <= 100)
			set = 9;
		if (counter > s_a->size / 2 && sup->size > 100)
			set = 20;
		blk += sup->size / set;
		while (counter < blk && counter < sup->size)
		{
			cheap_index = find_cheapest(s_a, sup, blk, blk - sup->size / set);
			push_right_place_b(s_a, s_b, cheap_index, rotations);
			counter++;
		}
	}
}

void	sort(t_ps *stack_a, t_ps *stack_b, t_ps *support)
{
	int	rotations[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		rotations[i] = 0;
		i++;
	}
	if (check_if_sorted(stack_a))
		return ;
	if (stack_a->size <= 10)
	{
		mini_sort(stack_a, stack_b);
		return ;
	}
	else
		large_sort(stack_a, stack_b, support, rotations);
	rotate_back(stack_b);
	push_back(stack_a, stack_b);
}
