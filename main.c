/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:39:04 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/03 22:49:03 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_ps stack_a;
	t_ps stack_b;
	int i;
	
	i = 0;
	
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (parse_args(&stack_a, &stack_b, argc, argv))
		return (0);

	printf("before: ");
	while (i < stack_a.size)
	{
		printf("%d ", stack_a.array[i]);
		i++;
	}
	two_stack_sort(&stack_a, &stack_b);
	
	i = 0;
	printf("\n");
	printf(" after: ");
	while (i < stack_a.size)
	{
		printf("%d ", stack_a.array[i]);
		i++;
	}

	return (0);
}
