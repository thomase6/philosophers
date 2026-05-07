/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:02:10 by texenber          #+#    #+#             */
/*   Updated: 2026/05/07 15:45:14 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philos.h"

int	check_meals(t_data *data)
{
	int		i;
	int64_t	full;

	if (data->num_of_meals == -1)
		return (0);
	full = 0;
	i = 0;
	while (i < data->p_num)
	{
		pthread_mutex_lock(&data->philos[i].meal_mutex);
		if (data->philos[i].meals_eaten >= data->num_of_meals)
			full++;
		pthread_mutex_unlock(&data->philos[i].meal_mutex);
		i++;
	}
	if (full == data->p_num)
	{
		pthread_mutex_lock(&data->death_mutex);
		data->death_flag = 1;
		pthread_mutex_unlock(&data->death_mutex);
		return (1);
	}
	return (0);
}

int	check_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->p_num)
	{
		pthread_mutex_lock(&data->philos[i].meal_mutex);
		if (get_time() - data->philos[i].last_meal > data->time_to_d)
		{
			pthread_mutex_unlock(&data->philos[i].meal_mutex);
			pthread_mutex_lock(&data->death_mutex);
			data->death_flag = 1;
			pthread_mutex_unlock(&data->death_mutex);
			print_status(&data->philos[i], DIED);
			return (1);
		}
		pthread_mutex_unlock(&data->philos[i].meal_mutex);
		i++;
	}
	return (0);
}

void	*monitor_r(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (check_death(data) || check_meals(data))
			return (NULL);
		usleep(50);
	}
	return (NULL);
}
