/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:55:56 by alrey             #+#    #+#             */
/*   Updated: 2025/07/19 19:03:48 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	if (((((long) count) < 0) || (((long) size) < 0)) && (count && size))
		return (NULL);
	size *= count;
	ptr = malloc(sizeof(char) * size);
	if (!ptr)
		return (NULL);
	while (size--)
		ptr[size] = '\0';
	return (ptr);
}

static void	distribute_forks(t_sim *sim, t_philo *philos)
{
	t_ulong	i;

	i = 0;
	sim->start = get_time_ms();
	while (i < sim->n_philosophers)
	{
		philos[i].sim = sim;
		philos[i].rfork = &(philos[i + 1 % sim->n_philosophers].fork);
		mutexc_set(&philos[i].last_meal, (void *)sim->start);
		pthread_create(&philos[i].thread, NULL,
			(void *)&philosopher_life, &philos[i]);
		i++;
	}
}

t_philo	*init_philos(t_sim *sim)
{
	t_ulong	i;
	t_philo	*philos;

	philos = ft_calloc(sim->n_philosophers, sizeof(t_philo));
	if (philos != NULL)
	{
		i = 0;
		while (i < sim->n_philosophers)
		{
			philos[i].id = i + 1;
			pthread_mutex_init(&philos[i].fork, NULL);
			philos[i].sim = sim;
			i++;
		}
		distribute_forks(sim, philos);
	}
	return (philos);
}
