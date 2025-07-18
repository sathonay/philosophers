/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:55:56 by alrey             #+#    #+#             */
/*   Updated: 2025/07/08 20:30:17 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool check_death(t_philo *philo)
{
	t_ulong time;
	
	time = get_time_ms();
	return (time - philo->last_meal > philo->sim->time_to_die);
}

static void philosopher_death(t_philo *philo)
{
		if (check_death(philo))
		{
			print(philo, "died");
			philo->sim->running = false;
		}
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->rfork);	
}

void schrodinger_sleep(t_philo *philo, t_ulong tts)
{
	t_ulong	time;

	time = get_time_ms();
	while (philo->sim->running && !check_death(philo) && get_time_ms() - time <= tts)
	{
		usleep(10);
	}
}

void *philosopher_life_schrodinger_cat(t_philo *philo)
{
	while (philo->sim->running)
	{
		printf("%ld ticking\n", philo->id);
		pthread_mutex_lock(&philo->fork);
		pthread_mutex_lock(philo->rfork);	
		philosopher_death(philo);
		print(philo, "has taken a fork");
		philo->last_meal = get_time_ms();
		print(philo, "is eating");
		schrodinger_sleep(philo, philo->sim->time_to_eat * 1000);
		philosopher_death(philo);
		print(philo, "is sleeping");
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->rfork);	
		schrodinger_sleep(philo, philo->sim->time_to_sleep * 1000);
		philosopher_death(philo);
		print(philo, "is thinking");
	}
	return (NULL);
}

static void distribute_forks(t_sim *sim, t_philo *philos)
{
	t_ulong	i;

	i = 0;	
	while (i < sim->n_philosophers)
	{
		philos[i].sim = sim;
		if (i == sim->n_philosophers - 1)
			philos[i].rfork = &philos[0].fork;
		else
			philos[i].rfork = &philos[i + 1].fork;
		pthread_create(&philos[i].thread, NULL,
						(void *)&philosopher_life_schrodinger_cat, &philos[i]);
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
			philos[i].last_meal = get_time_ms();
			pthread_mutex_init(&philos[i].fork, NULL);
			philos[i].sim = sim;
			i++;	
		}
		distribute_forks(sim, philos);
	}
	return (philos);
}
