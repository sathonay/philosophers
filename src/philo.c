/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:29:18 by alrey             #+#    #+#             */
/*   Updated: 2025/07/18 13:31:02 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "libft.h"

static void	free_philos(t_sim *sim, t_philo *philos)
{
	t_ulong	i;

	i = 0;
	while (i < sim->n_philosophers)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	free(philos);
}

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static int	is_str_ulong(char *str)
{
	char	c;
	int		i;

	c = '+';
	i = 0;
	while (*str && *str == '0')
		str++;
	while (ft_isdigit(str[i]) && i <= 20)
		i++;
	return (str[i] == '\0'
		&& (i < 20 || ft_strcmp(str, "18446744073709551615") <= 0));
}

static bool	check_input(int argc, char **argv)
{
	if (argc < 5)
		return (false);
	if (!(is_str_ulong(argv[1]) && is_str_ulong(argv[2])
			&& is_str_ulong(argv[3]) && is_str_ulong(argv[4])))
		return (false);
	if (argc > 5 && !is_str_ulong(argv[5]))
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_sim	sim;
	t_philo	*philos;

	if (!check_input(argc, argv))
		return (printf("not enough arguments/invalid (only positive numbers): \
[n_philo] [tt_die] [tt_eat] [tt_sleep] (max_meal)"), 1);
	sim.running = true;
	pthread_mutex_init(&sim.print, NULL);
	sim.n_philosophers = ft_atoul(argv[1]);
	sim.time_to_die = ft_atoul(argv[2]);
	sim.time_to_eat = ft_atoul(argv[3]);
	sim.time_to_sleep = ft_atoul(argv[4]);
	if (argc > 5)
		sim.max_meal = ft_atoul(argv[5]);
	else
		sim.max_meal = -1;
	philos = init_philos(&sim);
	free_philos(&sim, philos);
	pthread_mutex_unlock(&sim.print);
	pthread_mutex_destroy(&sim.print);
}
