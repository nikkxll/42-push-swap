/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:49:09 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/03 18:02:12 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	array_creation(t_ps *stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		stack_a->array[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	stack_a->size = argc - 1;
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

int	parse_args(t_ps *stack_a, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	stack_a->array = (int *)malloc((argc - 1) * sizeof(int));
	if (!stack_a->array)
		return (0);
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == 0)
			return (write(2, "Error\n", 6));
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
	array_creation(stack_a, argc, argv);
	if (check_duplicates(argc, stack_a))
		return (write(2, "Error\n", 6));
	return (0);
}
