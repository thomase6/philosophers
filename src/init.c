/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:35:48 by texenber          #+#    #+#             */
/*   Updated: 2026/05/07 15:42:49 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philos.h"

int	init_mutex(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (pthread_mutex_destroy(&data->death_mutex), 1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->p_num);
	if (!data->forks)
		return (destroy_print_and_death_mutex(data), 1);
	i = 0;
	while (i < data->p_num)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			destroy_print_and_death_mutex(data);
			destroy_fork_mutexes(data, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_data(t_data *data, char **av)
{
	data->p_num = ft_atoi(av[1]);
	data->time_to_d = ft_atoi(av[2]);
	data->time_to_e = ft_atoi(av[3]);
	data->time_to_s = ft_atoi(av[4]);
	data->num_of_meals = -1;
	if (av[5])
		data->num_of_meals = ft_atoi(av[5]);
	data->death_flag = 0;
	if (init_mutex(data) == 1)
		return (ft_putstr_fd(MUTEX_FAIL, 2), 1);
	return (0);
}

int	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philos) * data->p_num);
	if (!data->philos)
		return (destroy_multiple_mutexes(data),
			ft_putstr_fd(ALLOC_FAIL, 2), 1);
	i = 0;
	while (i < data->p_num)
	{
		data->philos[i].id = i + 1;
		data->philos[i].last_meal = data->start;
		data->philos[i].meals_eaten = 0;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->p_num];
		if (pthread_mutex_init(&data->philos[i].meal_mutex, NULL) != 0)
		{
			destroy_multiple_mutexes(data);
			destroy_meal_mutex(data, i);
			return (ft_putstr_fd(MUTEX_FAIL, 2), 1);
		}
		i++;
	}
	return (0);
}
