/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:37:15 by alrey             #+#    #+#             */
/*   Updated: 2025/07/20 15:33:02 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//eeesssttt
//   eeesssttt
//eeesssttt
//   eeesssttt
void	print(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->sim->print);
	if (mutexc_get(&philo->sim->running))
	{
		printf("%ld %lu %s\n",
			get_time_ms() - philo->sim->start, philo->id, msg);
	}
	pthread_mutex_unlock(&philo->sim->print);
}
