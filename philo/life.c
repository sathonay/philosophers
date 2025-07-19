/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:21:35 by alrey             #+#    #+#             */
/*   Updated: 2025/07/19 22:53:10 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_death(t_philo *philo)
{
	t_ulong	time;

	time = get_time_ms();
	return (time - (t_ulong) mutexc_get(&philo->last_meal)
		> philo->sim->time_to_die);
}

static void	eat(t_philo *philo)
{
	pthread_mutex_t	*forks[2];

	if (philo->id % 2 == 0)
	{
		forks[0] = &philo->fork;
		forks[1] = philo->rfork;
	}
	else
	{
		forks[1] = &philo->fork;
		forks[0] = philo->rfork;
	}
	pthread_mutex_lock(forks[0]);
	print(philo, "has taken a fork");
	pthread_mutex_lock(forks[1]);
	print(philo, "has taken a fork");
	print(philo, "is eating");
	mutexc_set(&philo->last_meal, (void *) get_time_ms());
	mssleep(philo->sim, philo->sim->time_to_eat);
	pthread_mutex_unlock(forks[1]);
	pthread_mutex_unlock(forks[0]);
}

void	*philosopher_life(t_philo *philo)
{
	while (mutexc_get(&philo->sim->running) && &philo->fork != philo->rfork
		&& (t_ulong) mutexc_get(&philo->meal_count) < philo->sim->max_meal)
	{
		if (get_time_ms() - (t_ulong) mutexc_get(&philo->last_meal)
			> (philo->sim->time_to_die / philo->sim->n_philosophers))
		{
			eat(philo);
			if ((t_ulong) mutexc_perform(&philo->meal_count, &increment)
				>= philo->sim->max_meal)
				return (NULL);
			print(philo, "is sleeping");
			if (philo->sim->time_to_sleep != 0)
				mssleep(philo->sim, philo->sim->time_to_sleep);
			print(philo, "is thinking");
		}
	}
	return (NULL);
}

static bool	philosopher_murder_attempt(t_philo *philo)
{
	if (check_death(philo))
	{
		pthread_mutex_lock(&philo->sim->print);
		mutexc_set(&philo->sim->running, false);
		printf("%ld %lu %s\n",
			get_time_ms() - philo->sim->start, philo->id, "died");
		pthread_mutex_unlock(&philo->sim->print);
		return (true);
	}
	return (false);
}

int	jack_the_ripper(t_sim *sim, t_philo *philos)
{
	bool	all_ate;
	t_ulong	i;

	all_ate = false;
	while (mutexc_get(&sim->running) && !all_ate)
	{
		all_ate = true;
		i = 0;
		while (i < sim->n_philosophers)
		{
			if ((t_ulong) mutexc_get(&philos[i].meal_count) < sim->max_meal
				|| sim->max_meal == (t_ulong) - 1)
				all_ate = false;
			if (philosopher_murder_attempt(&philos[i]))
				return (1);
			i++;
		}
	}
	return (0);
}
