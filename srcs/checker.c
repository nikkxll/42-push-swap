/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:01:06 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/09 10:57:23 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_rev_rotate(t_ps *a, t_ps *b, char *line)
{
	if (line[2] == 'a')
		reverse_rotate(a);
	else if (line[2] == 'b')
		reverse_rotate(b);
	else if (line[2] == 'r')
		reverse_rotate_each(a, b);
}

char	*ft_check(t_ps *a, t_ps *b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		swap(a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		swap(b);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		push(b, a);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		push(a, b);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		rotate(a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rotate(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		ft_check_rev_rotate(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rotate_each(a, b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		swap_each(a, b);
	else
		throw_error();
	return (get_next_line(0));
}

void	ft_checker_sub(t_ps *a, t_ps *b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_check(a, b, line);
		free(tmp);
	}
	if (b->size != 0)
		write(1, "KO\n", 3);
	else if (!check_if_sorted(a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char **argv)
{
	t_ps	*a;
	t_ps	*b;
	char	*line;

	if (argc < 2)
		return (0);
	b = (t_ps *)malloc(sizeof(t_ps));
	if (!b)
		throw_error();
	a = (t_ps *)malloc(sizeof(t_ps));
	if (!a)
		throw_error();
	if (array_creation(a, b, argc, argv))
		throw_error();
	line = get_next_line(0);
	if (!line && !check_if_sorted(a))
		write(1, "KO\n", 3);
	else if (!line && check_if_sorted(a))
		write(1, "OK\n", 3);
	else
		ft_checker_sub(a, b, line);
	free(b->array);
	free(a->array);
	return (0);
}
