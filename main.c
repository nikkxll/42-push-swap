/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:39:04 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/03 19:01:59 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_ps stack_a;
	t_ps stack_b;
	
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (parse_args(&stack_a, argc, argv))
		return (0);
	// swap_a(&stack_a);
	// reverse_rotate_a(&stack_a);
	// rotate_a(&stack_a);
	// push_a_b(&stack_a, &stack_b);
	push_a_b(&stack_a, &stack_b);
	push_b_a(&stack_b, &stack_a);
	printf("stack a size:%d\n", stack_a.size);
	printf("stack a before:%d %d %d\n", stack_a.array[0], stack_a.array[1], stack_a.array[2]);
	one_stack_sort(&stack_a, stack_a.array[0], stack_a.array[1], stack_a.array[2]);
	printf("stack a after:%d %d %d\n", stack_a.array[0], stack_a.array[1], stack_a.array[2]);
	// push(stack_a, stack_b);
	// push(stack_b, stack_a);
	// print_linked_list(stack_a, stack_b);
	return (0);
}
