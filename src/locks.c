/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:03:59 by texenber          #+#    #+#             */
/*   Updated: 2026/05/07 16:22:52 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philos.h"

int	is_dead(t_data *data)
{
	int	res;

	pthread_mutex_lock(&data->death_mutex);
	res = data->death_flag;
	pthread_mutex_unlock(&data->death_mutex);
	return (res);
}

void	print_status(t_philos *philo, char *msg)
{
	int64_t	timestamp;

	timestamp = 0;
	pthread_mutex_lock(&philo->data->print_mutex);
	pthread_mutex_lock(&philo->data->death_mutex);
	if (philo->data->death_flag == 1 && ft_strcmp(msg, DIED))
	{
		pthread_mutex_unlock(&philo->data->death_mutex);
		pthread_mutex_unlock(&philo->data->print_mutex);
		return ;
	}
	timestamp = (get_time() - philo->data->start) / 1000;
	printf("%ld %ld %s\n", timestamp, philo->id, msg);
	pthread_mutex_unlock(&philo->data->death_mutex);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
