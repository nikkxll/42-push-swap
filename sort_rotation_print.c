/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotation_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:29:41 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/07 15:00:57 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotation_steps_utils_first(int *rotations, int a, int b)
{
	if (rotations[a] != 0 || rotations[b] != 0)
	{
		while (rotations[a] != 0 && rotations[b] != 0)
		{
			write(1, "rr\n", 3);
			rotations[a] -= 1;
			rotations[b] -= 1;
		}
		if (rotations[a] == 0)
		{
			while (rotations[b] != 0)
			{
				write(1, "rb\n", 3);
				rotations[b] -= 1;
			}
		}
		else
		{
			while (rotations[a] != 0)
			{
				write(1, "ra\n", 3);
				rotations[a] -= 1;
			}
		}
	}
}

static void	rotation_steps_utils_second(int *rotations, int a, int b)
{
	if (rotations[a] != 0 || rotations[b] != 0)
	{
		while (rotations[a] != 0 && rotations[b] != 0)
		{
			write(1, "rrr\n", 4);
			rotations[a] -= 1;
			rotations[b] -= 1;
		}
		if (rotations[a] == 0)
		{
			while (rotations[b] != 0)
			{
				write(1, "rrb\n", 4);
				rotations[b] -= 1;
			}
		}
		else
		{
			while (rotations[a] != 0)
			{
				write(1, "rra\n", 4);
				rotations[a] -= 1;
			}
		}
	}
}

void	rotation_steps(int *rotations)
{
	while (rotations[0] != 0 || rotations[1] != 0
		|| rotations[2] != 0 || rotations[3] != 0)
	{
		rotation_steps_utils_first(rotations, 0, 1);
		rotation_steps_utils_second(rotations, 2, 3);
	}
}
