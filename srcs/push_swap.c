/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:39:04 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 18:21:24 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	throw_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	msg_memory_free(t_ps *stack_a, t_ps *stack_b)
{
	free(stack_a->array);
	free(stack_b->array);
	free(stack_a);
	free(stack_b);
	return (1);
}

static void	memory_free(t_ps *stack_b, t_ps *support)
{
	free(support->array);
	free(stack_b->array);
	free(support);
	free(stack_b);
}

static void	support_creation(t_ps *sup, t_ps *s_a, t_ps *s_b, int argc)
{
	if (!sup)
	{
		free(s_a);
		free(s_b);
		throw_error();
	}
	sup->array = (int *)malloc((argc - 1) * sizeof(int));
	if (!sup->array)
	{
		msg_memory_free(s_a, s_b);
		throw_error();
	}
	support_array_creation(sup, s_a);
}

t_ps	*push_swap(int argc, char *argv[])
{
	t_ps	*stack_a;
	t_ps	*stack_b;
	t_ps	*support;

	if (argc < 2)
		throw_error();
	stack_a = (t_ps *)malloc(sizeof(t_ps));
	if (!stack_a)
		throw_error();
	stack_b = (t_ps *)malloc(sizeof(t_ps));
	if (!stack_b)
	{
		free(stack_a);
		throw_error();
	}
	if (array_creation(stack_a, stack_b, argc, argv))
		throw_error();
	support = (t_ps *)malloc(sizeof(t_ps));
	support_creation(support, stack_a, stack_b, argc);
	sort(stack_a, stack_b, support);
	memory_free(stack_b, support);
	return (stack_a);
}
