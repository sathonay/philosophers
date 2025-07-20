/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:38:29 by alrey             #+#    #+#             */
/*   Updated: 2025/07/20 15:32:29 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

void	*increment(void *value)
{
	return (value + 1);
}
