/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:53:01 by texenber          #+#    #+#             */
/*   Updated: 2026/05/07 15:45:41 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philos.h"

void	*routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
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
