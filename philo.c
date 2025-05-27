#include "philo.h"
#include "libft.h"


long get_current_time_ms()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
}

int main(int agrc, char **argv, char **env)
{
	t_philo philos;
	if (argc < 5)
		return (printf("not enough arguments"), 1);
	philos.number_of_philosophers = ft_atoul(argv[1]);
	philos.time_to_die = ft_atoul(argv[2]);
	philos.time_to_eat = ft_atoul(argv[3]);
	philos.time_to_sleep = ft_atoul(argv[4]);
	if (argc > 5)
		philos.number_of_times_each_philosopher_must_eat = ft_atoul(argv[5]);
	else
		philos.number_of_times_each_philosopher_must_eat = 0;
	printf("%ld\n", get_current_time_ms());
}
