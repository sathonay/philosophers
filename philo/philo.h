/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:53:50 by alrey             #+#    #+#             */
/*   Updated: 2025/07/20 15:47:13 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef unsigned char	t_ubyte;
typedef unsigned short	t_ushort;
typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

typedef struct s_mutexc
{
	pthread_mutex_t	mutex;
	void			*value;
}					t_mutexc;

typedef struct s_sim
{
	t_mutexc		running;
	t_ulong	n_philosophers;
	t_ulong	time_to_die;
	t_ulong	time_to_eat;
	t_ulong	time_to_sleep;
	t_ulong	max_meal;
	t_ulong			start;
	pthread_mutex_t	print;
}				t_sim;

typedef struct s_philo
{
	t_ulong			id;
	t_mutexc		last_meal;
	t_mutexc		meal_count;
	pthread_mutex_t	fork;
	pthread_mutex_t	*rfork;
	pthread_t		thread;
	t_sim			*sim;
}				t_philo;

void			print(t_philo *philo, char *msg);

t_philo			*init_philos(t_sim *sim);

void			*philosopher_life(t_philo *philo);

int				jack_the_ripper(t_sim *sim, t_philo *philos);

long			get_time_ms(void);

long			ft_atol(const char *str);

unsigned long	ft_atoul(const char *str);

void			mutexc_init(t_mutexc *mutexc, void *default_value);

void			*mutexc_get(t_mutexc *mutexc);

void			mutexc_set(t_mutexc *mutexc, void *value);

void			*mutexc_perform(t_mutexc *mutexc, void *f(void *));

int				ft_strcmp(char *s1, char *s2);

int				ft_isdigit(int c);

void			*increment(void *value);

void			mssleep(t_sim *sim, t_ulong tts);

t_ulong			ulmax(t_ulong a, t_ulong b);

t_ulong			ulmin(t_ulong a, t_ulong b);
#endif 
