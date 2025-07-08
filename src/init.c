/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:55:56 by alrey             #+#    #+#             */
/*   Updated: 2025/07/07 06:29:17 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philosopher_life(t_philo *philo)
{
	while (philo->sim->running)
	{
		pthread_mutex_lock(&philo->fork);
		pthread_mutex_lock(philo->rfork);	
		print(philo, "has taken a fork");
		philo->last_meal = get_time_ms();
		print(philo, "is eating");
		usleep(philo->sim->time_to_eat);
		print(philo, "is sleeping");
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->rfork);	
		usleep(philo->sim->time_to_sleep);
		print(philo, "is thinking");
	}
}

t_philo	*init_philos(t_sim *sim)
{
	int		i;
	t_philo	*philos;

	philos = ft_calloc(sim->n_philosophers, sizeof(t_philo));
	i = 0;	
	while (i < sim->n_philosophers)
	{
		philos[i].id = i + 1;
		pthread_mutex_init(&philos[i].fork);
		philos[i].sim = sim;
		i++;	
	}
	i = 0;	
	while (i < sim->n_philosophers)
	{
		philos[i].sim = sim;
		if (i == sim->n_philosophers - 1)
			philos[i].rfork = philos[0].fork;
		else
			philos[i].rfork = philos[i + 1].fork;
		pthread_create(&philos[i].thread, NULL, &philos[i]);
		i++;	
	}
}
