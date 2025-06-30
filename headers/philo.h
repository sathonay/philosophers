/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:53:50 by alrey             #+#    #+#             */
/*   Updated: 2025/06/30 23:59:17 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "libft.h"

enum	e_phil_state
{
	DEAD,
	FORK,
	EATING,
	SLEEPING,
	THINGKING
};

typedef struct	s_phil
{
	pthread_t thread;
}				t_phil;

typedef struct	s_philo
{
	unsigned long	n_philosophers;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	number_of_times_each_philosopher_must_eat;
	enum e_phil_state *philos;
	unsigned long	*forks;
	
}				t_philo;

long			get_current_time_ms();

long			ft_atol(const char *str);

unsigned long	ft_atoul(const char *str);

#endif 
