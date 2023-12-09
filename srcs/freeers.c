/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:25:55 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/09 12:35:20 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	msg_memory_free(t_ps *stack_a, t_ps *stack_b)
{
	free(stack_a->array);
	free(stack_b->array);
	free(stack_a);
	free(stack_b);
	return (1);
}

void	memory_free(t_ps *stack_b, t_ps *support)
{
	free(support->array);
	free(stack_b->array);
	free(support);
	free(stack_b);
}

void	free_aft_sup(t_ps *stack_a, t_ps *stack_b, int argc, char **args)
{
	free(stack_a);
	free(stack_b);
	free_args(argc, args);
	throw_error();
}

void	free_aft_sa(int argc, char **args)
{
	free_args(argc, args);
	throw_error();
}

void	free_aft_sb(t_ps *stack_a, int argc, char **args)
{
	free(stack_a);
	free_args(argc, args);
	throw_error();
}
