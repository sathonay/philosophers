#include "philo.h"
#include "libft.h"


long get_current_time_ms()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	printf("%ld\n", tv.tv_usec);
	return (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
}

int main(int argc, char **argv, char **env)
{
	t_philo philo;
	if (argc < 5)
		return (printf("not enough arguments"), 1);
	philo.n_philosophers = ft_atoul(argv[1]);
	philo.time_to_die = ft_atoul(argv[2]);
	philo.time_to_eat = ft_atoul(argv[3]);
	philo.time_to_sleep = ft_atoul(argv[4]);
	if (argc > 5)
		philo.number_of_times_each_philosopher_must_eat = ft_atoul(argv[5]);
	else
		philo.number_of_times_each_philosopher_must_eat = 0;
	(void) philo;
	(void) env;

	init_philos(&philo);
	printf("started at: %ld\n", philo.start);
}

