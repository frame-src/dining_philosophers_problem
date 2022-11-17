/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:49:43 by frmessin          #+#    #+#             */
/*   Updated: 2022/11/16 13:51:32 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static bool	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (true);
	else
		return (false);
}

static bool	ft_isnumeric(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

static int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		i++;
	}
	return (i);
}

static int	check_limits(char *string)
{
	int		i;
	char	*min_integer;

	i = ft_strlen(string);
	min_integer = (char *)"-2147483648";
	if (string[0] == '+' || string[0] == '-')
		i--;
	if (i > 10)
		return (-1);
	i = 0;
	while (string[i])
	{
		if (string[i] != min_integer[i])
			break ;
		i++;
	}
	if (!string[i])
		return (-2147483648);
	return (1);
}

int	ft_atoi(char *string)
{
	int	num;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(string[i]))
		i++;
	if (check_limits(string) < 0)
		return (0);
	if (check_limits(string) == -2147483648)
		return (-2147483648);
	if (string[i] == '+' || string[i] == '-')
	{
		if (string[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isnumeric(string[i]))
	{
		num = (num * 10) + (string[i] - '0');
		i++;
	}
	return (sign * num);
}
