#include "philo.h"


long get_current_time_ms()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
}

int main(int agrc, char **argv, char **env)
{
	printf("%ld\n", get_current_time_ms());
}
