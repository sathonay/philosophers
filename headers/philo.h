/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:53:50 by alrey             #+#    #+#             */
/*   Updated: 2025/07/18 13:22:29 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "libft.h"

//# define ULONG __u_long
//# define UINT __u_int

typedef char			t_byte;
typedef short			t_short;
typedef int				t_int;
typedef long			t_long;

typedef unsigned char	t_ubyte;
typedef unsigned short	t_ushort;
typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

typedef struct s_sim
{
	bool			running;
	unsigned long	n_philosophers;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	max_meal;
	pthread_mutex_t	print;
}				t_sim;

typedef struct s_philo
{
	t_ulong			id;
	t_ulong			last_meal;
	t_ulong			meal_count;
	pthread_mutex_t	fork;
	pthread_mutex_t	*rfork;
	pthread_t		thread;
	t_sim			*sim;
}				t_philo;

void			print(t_philo *philo, char *msg);

t_philo			*init_philos(t_sim *sim);

void			*philosopher_life_schrodinger(t_philo *philo);

long			get_time_ms(void);

long			ft_atol(const char *str);

unsigned long	ft_atoul(const char *str);

#endif 
