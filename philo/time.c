/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:02:56 by alrey             #+#    #+#             */
/*   Updated: 2025/07/19 19:06:32 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

void	mssleep(t_sim *sim, t_ulong tts)
{
	t_ulong	time;

	time = get_time_ms();
	while (mutexc_get(&sim->running) && get_time_ms() - time < tts)
		usleep(1);
}
