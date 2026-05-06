/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:03:49 by texenber          #+#    #+#             */
/*   Updated: 2026/05/06 09:21:12 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philos.h"

void	destroy_meal_mutex(t_data *data, int count)
{
	int	i;
	
	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&data->philos[i].meal_mutex);
		i++;
	}
	if (data->philos)
		free(data->philos);
}

void	destroy_fork_mutexes(t_data *data, int count)
{
	int	i;
	
	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	if (data->forks)
		free(data->forks);
}

void	cleanup(t_data *data)
{
	if (data->philos)
		destroy_meal_mutex(data, data->p_num);
	destroy_fork_mutexes(data, data->p_num);
	pthread_mutex_destroy(&data->death_mutex);
	pthread_mutex_destroy(&data->print_mutex);
}
