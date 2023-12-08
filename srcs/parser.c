/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:49:09 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 18:21:14 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	converter(t_ps *list, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		list->array[i - 1] = ft_atoi(argv[i]);
		if (list->array[i - 1] == 0)
		{
			while (argv[i][j] != '\0')
			{
				j = 0;
				if (argv[i][j] != '0')
					return (1);
				j++;
			}
		}
		i++;
	}
	list->size = argc - 1;
	return (0);
}

static int	check_duplicates(int argc, t_ps *stack_a)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (stack_a->array[i] == stack_a->array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_valid_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == 0)
			return (1);
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	array_creation(t_ps *stack_a, t_ps *stack_b, int argc, char **argv)
{
	stack_a->array = (int *)malloc((argc - 1) * sizeof(int));
	if (!stack_a->array)
		return (1);
	stack_b->array = (int *)malloc((argc - 1) * sizeof(int));
	if (!stack_b->array)
	{
		free(stack_b->array);
		return (1);
	}
	stack_b->size = 0;
	if (is_valid_args(argc, argv))
		return (msg_memory_free(stack_a, stack_b));
	if (converter(stack_a, argc, argv))
		return (msg_memory_free(stack_a, stack_b));
	if (check_duplicates(argc, stack_a))
		return (msg_memory_free(stack_a, stack_b));
	return (0);
}
