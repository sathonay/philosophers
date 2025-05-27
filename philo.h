/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:53:50 by alrey             #+#    #+#             */
/*   Updated: 2025/05/28 00:10:42 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

enum	e_phil_state
{
	DEAD,
	FORK,
	EATING,
	SLEEPING,
	THINGKING
};

typedef struct	s_philo
{
	unsigned long	number_of_philosophers;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	number_of_times_each_philosopher_must_eat;
}				t_philo;

long			get_current_time_ms();

long			ft_atol(const char *str)

unsigned long	ft_atoul(const char *str);

#endif 
