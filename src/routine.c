/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:53:01 by texenber          #+#    #+#             */
/*   Updated: 2026/05/07 18:58:55 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philos.h"

void	*routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	pthread_mutex_lock(&philo->data->ready_mutex);
	if (philo->data->ready == -1)
		return (pthread_mutex_unlock(&philo->data->ready_mutex), NULL);
	pthread_mutex_unlock(&philo->data->ready_mutex);
	if (philo->id % 2 == 0)
		ft_sleep(1, philo->data);
	while (!is_dead(philo->data))
	{
		eating(philo);
		if (is_dead(philo->data))
			return (NULL);
		sleeping(philo);
		if (is_dead(philo->data))
			return (NULL);
		thinking(philo);
	}
	return (NULL);
}
