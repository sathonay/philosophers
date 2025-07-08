/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:37:15 by alrey             #+#    #+#             */
/*   Updated: 2025/07/07 04:45:15 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print(t_philo *philo, char *msg)
{
	if (&philo->sim->running)
	{
		pthread_mutex_lock(&philo->sim->print)
		printf("%ul %ul %s", get_time_ms(), philo->id, msg);
		pthread_mutex_unlock(&philo->sim->print)
	}
}
