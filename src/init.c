/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:55:56 by alrey             #+#    #+#             */
/*   Updated: 2025/07/18 17:00:23 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	distribute_forks(t_sim *sim, t_philo *philos)
{
	t_ulong	i;

	i = 0;
	while (i < sim->n_philosophers)
	{
		philos[i].sim = sim;
		if (i == sim->n_philosophers - 1)
			philos[i].rfork = &(philos[0].fork);
		else
			philos[i].rfork = &(philos[i + 1].fork);
		pthread_create(&philos[i].thread, NULL,
			(void *)&philosopher_life, &philos[i]);
		i++;
	}
}

t_philo	*init_philos(t_sim *sim)
{
	t_ulong	i;
	t_philo	*philos;

	sim->start = get_time_ms();
	philos = ft_calloc(sim->n_philosophers, sizeof(t_philo));
	if (philos != NULL)
	{
		i = 0;
		while (i < sim->n_philosophers)
		{
			philos[i].id = i + 1;
			philos[i].last_meal = sim->start;
			pthread_mutex_init(&philos[i].fork, NULL);
			philos[i].sim = sim;
			i++;
		}
		distribute_forks(sim, philos);
	}
	return (philos);
}
