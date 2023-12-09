/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_one_argv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:06:26 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/09 12:37:58 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_nums(const char *str)
{
	int	wc;
	int	in_word;

	wc = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\r')
		{
			if (!in_word)
			{
				in_word = 1;
				wc++;
			}
		}
		else
			in_word = 0;
		str++;
	}
	return (wc);
}

void	free_args(int argc, char **str)
{
	int	length;

	length = 0;
	while (length < argc)
	{
		free(str[length]);
		length++;
	}
	free(str);
}

static void	insert_null_at_beginning(char **args)
{
	int	length;
	int	i;

	length = 0;
	while (args[length] != NULL)
		length++;
	i = length;
	while (i >= 0)
	{
		args[i] = args[i - 1];
		i--;
	}
	args[0] = NULL;
}

t_ps	*push_swap_one_arg(int argc, char *argv[])
{
	t_ps	*stack_a;
	t_ps	*stack_b;
	t_ps	*support;
	char	**args;

	args = ft_split(argv[1], ' ');
	if (!args)
		throw_error();
	insert_null_at_beginning(args);
	stack_a = (t_ps *)malloc(sizeof(t_ps));
	if (!stack_a)
		free_aft_sa(argc, args);
	stack_b = (t_ps *)malloc(sizeof(t_ps));
	if (!stack_b)
		free_aft_sb(stack_a, argc, args);
	if (array_creation(stack_a, stack_b, argc, args))
		throw_error();
	support = (t_ps *)malloc(sizeof(t_ps));
	if (!support)
		free_aft_sup(stack_a, stack_b, argc, args);
	support_creation(support, stack_a, stack_b, argc);
	sort(stack_a, stack_b, support);
	memory_free(stack_b, support);
	free_args(argc, args);
	return (stack_a);
}
