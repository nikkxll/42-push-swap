/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:39:04 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/07 17:50:50 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	msg_memory_free(t_ps *stack_a, t_ps *stack_b)
{
	free(stack_a->array);
	free(stack_b->array);
	return (1);
}

static void	memory_free(t_ps *stack_a, t_ps *stack_b, t_ps *support)
{
	free(support->array);
	free(stack_a->array);
	free(stack_b->array);
}

int	main(int argc, char *argv[])
{
	t_ps	stack_a;
	t_ps	stack_b;
	t_ps	support;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (array_creation(&stack_a, &stack_b, argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	support.array = (int *)malloc((argc - 1) * sizeof(int));
	if (!support.array)
	{
		msg_memory_free(&stack_a, &stack_b);
		write(2, "Error\n", 6);
		return (0);
	}
	support_array_creation(&support, &stack_a);
	sort(&stack_a, &stack_b, &support);
	memory_free(&stack_a, &stack_b, &support);
	return (0);
}
