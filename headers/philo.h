/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:53:50 by alrey             #+#    #+#             */
/*   Updated: 2025/07/02 19:06:11 by alrey            ###   ########.fr       */
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
	t_ulong		id;
	pthread_t	thread;
	
}				t_phil;

typedef struct	s_philo
{
	unsigned long	start;
	unsigned long	n_philosophers;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	number_of_times_each_philosopher_must_eat;
	unsigned long	**forks;
	t_phil			**philos;	
}				t_philo;

int				init_philos(t_philo *philo);

// maybe an enum with NS MS S
long			get_time_ms();

long			ft_atol(const char *str);

unsigned long	ft_atoul(const char *str);

#endif 
