/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:39:04 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/02 17:49:19 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_linked_list(t_list *list_a, t_list *list_b)
{
	list_b = NULL;
	printf("list_a 1: %d ", (int)list_a->content);
	printf("\n");
	list_a = list_a->next;
	printf("list_a 2: %d ", (int)list_a->content);
	printf("\n");
	list_a = list_a->next;
	printf("list_a 3: %d ", (int)list_a->content);
	printf("\n");
// 	list_a = list_a->next;
// 	printf("list_a 4: %d ", list_a->content);
// 	printf("\n");
	// printf("list_b 1: %d ", list_b->content);
	// printf("\n");
	// list_b = list_b->next;
	// printf("list_b 2: %d ", list_b->content);
	// printf("\n");
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*temp_a;
	t_list	*temp_b;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack_a = NULL;
	stack_b = NULL;
	if (parse_args(&stack_a, argc, argv))
		return (0);
	// swap(stack_a);
	// reverse_rotate(list);
	// rotate(stack_a);
	// push(stack_a, stack_b);
	one_stack_sort(stack_a);
	// push(stack_a, stack_b);
	// push(stack_b, stack_a);
	// print_linked_list(stack_a, stack_b);
	while (stack_a)
	{
		temp_a = stack_a;
		stack_a = stack_a->next;
		free(temp_a);
	}
	while (stack_b)
	{
		temp_b = stack_b;
		stack_b = stack_b->next;
		free(temp_b);
	}
	return (0);
}
