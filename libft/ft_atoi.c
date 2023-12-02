/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:32:19 by dnikifor          #+#    #+#             */
/*   Updated: 2023/11/03 08:41:56 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <stdlib.h>
//	int atoi(const char *str);

// DESCRIPTION
//	The atoi() function converts the initial portion 
//	of the string pointed to by str to int representation.

#include "libft.h"

static int	sign_check(const char *str, int i)
{
	int	sign;

	sign = 1;
	if (str[i] == '-')
		sign = sign * -1;
	return (sign);
}

static int	numb_check(const char *str, int sign, int i, long num)
{
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num *= 10;
		num += str[i] - '0';
		i++;
		if (num < 0 && sign == 1)
			return (-1);
		else if (num < 0 && sign == -1)
			return (0);
	}
	return (sign * num);
}

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;
	int		i;
	long	res;

	i = 0;
	num = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v')
		|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
	{
		i++;
	}
	sign = sign_check(str, i);
	res = numb_check(str, sign, i, num);
	return (res);
}
