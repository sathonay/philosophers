#include "philo.h"
#include "libft.h"


long get_current_time_ms()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	printf("%ld\n", tv.tv_usec);
	return (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
}

int main(int argc, char **argv)
{
	t_sim sim;
	t_philo philos;

	if (argc < 5)
		return (printf("not enough arguments"), 1);
	sim.running = true;
	pthread_mutex_init(&sim.print, NULL);
	sim.n_philosophers = ft_atoul(argv[1]);
	sim.time_to_die = ft_atoul(argv[2]);
	sim.time_to_eat = ft_atoul(argv[3]);
	sim.time_to_sleep = ft_atoul(argv[4]);
	if (argc > 5)
		sim.must_eat = ft_atoul(argv[5]);
	else
		sim.must_eat = -1;
	philos = init_philos(sim);
	while(simi.running)
	{
		
	}
	pthread_mutex_unlock(&sim.print);
	pthread_mutex_destroy(&sim.print);
}

