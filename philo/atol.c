/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:15:52 by alrey             #+#    #+#             */
/*   Updated: 2025/07/18 20:00:32 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || ('\t' <= c && c <= '\r'));
}

long	ft_atol(const char *str)
{
	char	sign;
	long	val;

	sign = 1;
	val = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		sign = -1;
	}
	while (ft_isdigit(*str))
		val = val * 10 + *(str++) - '0';
	return (sign * val);
}

unsigned long	ft_atoul(const char *str)
{
	unsigned long	val;

	val = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		val = val * 10 + *(str++) - '0';
	return (val);
}
