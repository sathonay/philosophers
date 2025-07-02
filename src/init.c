/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:55:56 by alrey             #+#    #+#             */
/*   Updated: 2025/07/02 19:09:29 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void run(t_phil *phil)
{
	printf("phil %ld started thread %ld\n", phil->id, phil->thread);	
}

int	init_philo(t_phil **phil, t_ulong id)
{
	*phil = ft_calloc(sizeof(t_phil), 1);
	if (*phil == NULL)
		return (0);
	(*phil)->id = id;
	pthread_create(&(*phil)->thread, NULL, (void *) &run, *phil);
	return (1);
}
int	init_philos(t_philo *philo)
{
	t_ulong i;

	philo->philos = ft_calloc(sizeof(t_phil), philo->n_philosophers);
	philo->forks = ft_calloc(sizeof(unsigned long), philo->n_philosophers);
	if (philo->philos == NULL || philo->forks == NULL)
		return (0);
	philo->start = get_time_ms();
	i = 0;
	while (i < philo->n_philosophers)
	{
		init_philo(&philo->philos[i], i);
		i++;
	}
	return (1);
}