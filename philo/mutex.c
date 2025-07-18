/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrey <alrey@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:49:05 by alrey             #+#    #+#             */
/*   Updated: 2025/07/18 19:55:45 by alrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutexc_init(t_mutexc *mutexc, void *default_value)
{
	pthread_mutex_init(&mutexc->mutex, NULL);
	pthread_mutex_lock(&mutexc->mutex);
	mutexc->value = default_value;
	pthread_mutex_unlock(&mutexc->mutex);
}

void	*mutexc_get(t_mutexc *mutexc)
{
	void	*copy;

	pthread_mutex_lock(&mutexc->mutex);
	copy = mutexc->value;
	pthread_mutex_unlock(&mutexc->mutex);
	return (copy);
}

void	mutexc_set(t_mutexc *mutexc, void *value)
{
	pthread_mutex_lock(&mutexc->mutex);
	mutexc->value = value;
	pthread_mutex_unlock(&mutexc->mutex);
}

void	*mutexc_perform(t_mutexc *mutexc, void *f(void *))
{
	void	*copy;

	pthread_mutex_lock(&mutexc->mutex);
	mutexc->value = f(mutexc->value);
	copy = mutexc->value;
	pthread_mutex_unlock(&mutexc->mutex);
	return (copy);
}
