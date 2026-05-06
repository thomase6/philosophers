/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:03:59 by texenber          #+#    #+#             */
/*   Updated: 2026/05/06 16:07:32 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philos.h"

int		is_dead(t_data *data)
{
	int	res;

	pthread_mutex_lock(&data->death_mutex);
	res = data->death_flag;
	pthread_mutex_unlock(&data->death_mutex);
	return (res);
}

void	print_status(t_philos *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	pthread_mutex_lock(&philo->data->death_mutex);
	if (philo->data->death_flag == 1 && ft_strcmp(msg, DIED))
	{
		pthread_mutex_unlock(&philo->data->death_mutex);
		pthread_mutex_unlock(&philo->data->print_mutex);
		return;
	}
	printf("%ld %ld %s\n", get_time() - philo->data->start, philo->id, msg);
	pthread_mutex_unlock(&philo->data->death_mutex);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
