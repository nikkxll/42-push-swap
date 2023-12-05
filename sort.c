/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:29:36 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/05 20:03:09 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_num_index(t_ps *stack_b, int max)
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

static void	rotate_back(t_ps *stack_b)
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

static void	set_rotation(t_ps *stack_a, t_ps *stack_b, int min, int max, int *rotations)
{
	int	i;

	i = 0;
	if (stack_b->array[0] != min
		&& stack_b->array[stack_b->size - 1] != max
		&& stack_b->array[0] != max
		&& stack_b->array[stack_b->size - 1] != min
		&& stack_b->array[0] < stack_a->array[0]
		&& stack_b->array[stack_b->size - 1] > stack_a->array[0]
		&& stack_b->array[0] > stack_a->array[0]
		&& stack_b->array[stack_b->size - 1] < stack_a->array[0])
	{
		rotation_steps(rotations);
		push_a_b(stack_a, stack_b);
		return ;
	}
	while (i < stack_b->size)
	{
		if ((stack_b->array[i] == min && stack_b->array[i + 1] == max)
			|| (stack_b->array[i] == max && stack_b->array[i + 1] == min))
			i++;
		if ((stack_b->array[i] > stack_a->array[0] && stack_b->array[i + 1] < stack_a->array[0])
			|| (stack_b->array[i] < stack_a->array[0] && stack_b->array[i + 1] > stack_a->array[0]))
		{
			if (i < stack_b->size / 2)
			{
				while (i + 1 > 0)
				{
					rotate(stack_b);
					rotations[1] += 1;
					i--;
				}
				return ;
			}
			else
			{
				while (stack_b->size - i - 1 > 0)
				{
					reverse_rotate(stack_b);
					rotations[3] += 1;
					i++;
				}
				return ;
			}
		}
		i++;
	}
}

static void	set_rotation_min_max(t_ps *stack_b, int min, int max, int *rotations)
{
	int	i;

	i = 0;
	if ((stack_b->array[stack_b->size - 1] == min && stack_b->array[i] == max)
		|| (stack_b->array[stack_b->size - 1] == max && stack_b->array[i] == min))
		return ;
	while (stack_b->array[i] != min && stack_b->array[i] != max)
		i++;
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

static int	find_min_number(t_ps *stack_b)
{
	int	min;
	int	i;

	min = INT_MAX;
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

	max = INT_MIN;
	i = 0;
	while (i < stack_b->size)
	{
		if (stack_b->array[i] > max)
			max = stack_b->array[i];
		i++;
	}
	return (max);
}

static void	find_place(t_ps *stack_a, t_ps *stack_b, int *rotations)
{
	int	i;
	int	min;
	int	max;

	min = find_min_number(stack_b);
	max = find_max_number(stack_b);
	i = 0;
	if (stack_a->array[0] < min || stack_a->array[0] > max)
		set_rotation_min_max(stack_b, min, max, rotations);
	else
		set_rotation(stack_a, stack_b, min, max, rotations);
}

static void	push_right_place_b(t_ps *stack_a, t_ps *stack_b, int cheap_index, int *rotations)
{
	int	temp;

	temp = stack_a->array[cheap_index];
	if (cheap_index < stack_a->size / 2)
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
	if (stack_b->size == 0 || stack_b->size == 1)
	{
		rotation_steps(rotations);
		push_a_b(stack_a, stack_b);
	}
	else
	{
		if (stack_b->size == 3)
			three_num_desc_sort_b(stack_b, stack_b->array[0],
				stack_b->array[1], stack_b->array[2]);
		find_place(stack_a, stack_b, rotations);
		rotation_steps(rotations);
		push_a_b(stack_a, stack_b);
	}
}

static int	find_top(t_ps *stack_a, t_ps *support, int range_max, int start)
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

static int	find_bottom(t_ps *stack_a, t_ps *support, int range_max, int start)
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

static int	find_cheapest(t_ps *stack_a, t_ps *support, int range_max, int start)
{
	int	temp_up;
	int	temp_bottom;
	int	res;

	temp_up = find_top(stack_a, support, range_max, start);
	res = temp_up;
	temp_bottom = find_bottom(stack_a, support, range_max, start);
	if (stack_a->size - temp_bottom + 1 < temp_up)
		res = temp_bottom;
	return (res);
}

static void	large_sort(t_ps *stack_a, t_ps *stack_b, t_ps *support, int *rotations)
{
	int	counter;
	int	chunk_size;
	int	range;
	int	cheap_index;
	int	increment;
	// int i;

	// i = 0;
	counter = 0;
	chunk_size = 0;
	// if (stack_a->size > 100)
	// 	chunk_size = 9;
	if (stack_a->size <= 100)
		chunk_size = 6;
	else
		chunk_size = 14;
	range = 0;
	cheap_index = 0;
	while (counter < support->size)
	{
		increment = range;
		range += support->size / chunk_size;
		while (counter < range && counter < support->size)
		{
			cheap_index = find_cheapest(stack_a, support, range, increment);
			push_right_place_b(stack_a, stack_b, cheap_index, rotations);
			counter++;
			// i = 0;
			// while (i < stack_b->size)
			// {
			// 	write(1, ft_itoa(stack_b->array[i]), ft_strlen(ft_itoa(stack_b->array[i])));
			// 	write(1, "\n", 1);
			// 	i++;
			// }
		}
	}
}

// rotations array looks like: [ra, rb, rra, rrb]
void	sort(t_ps *stack_a, t_ps *stack_b, t_ps *support)
{
	int rotations[4] = {0, 0, 0, 0};
	
	if (check_if_sorted(stack_a))
		return ;
	if (stack_a->size <= 10)
	{
		mini_sort(stack_a, stack_b);
		return ;
	}
	else
	{
		large_sort(stack_a, stack_b, support, rotations);
	}
	rotate_back(stack_b);
	push_back(stack_a, stack_b);
}
