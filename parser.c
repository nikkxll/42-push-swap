/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:49:09 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/02 17:54:18 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ll_creation(t_list **list, int argc, char **argv, int *array)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		array[i - 1] = ft_atoi(argv[i]);
		linked_list_node_add(list, &array[i - 1]);
		i++;
	}
	return (array);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	check_duplicates(int argc, int *array)
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
			if (array[i] == array[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_args(t_list **list, int argc, char **argv)
{
	int	i;
	int	j;
	int	*array;

	i = 1;
	array = (int *)malloc((argc - 1) * sizeof(int));
	if (!array)
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
	ll_creation(list, argc, argv, array);
	if (check_duplicates(argc, array))
		return (write(2, "Error\n", 6));
	return (0);
}
